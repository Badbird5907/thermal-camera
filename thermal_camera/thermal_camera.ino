#include <Wire.h>
#include <Adafruit_MLX90640.h>
#include <SPI.h>
#include <TFT_eSPI.h>

#define LCD_LED_PIN 7
#define I2C_SCL_PIN 14
#define I2C_SDA_PIN 21

Adafruit_MLX90640 mlx;
float frame[32*24]; // 32x24 pixels

TFT_eSPI tft = TFT_eSPI(); // init display

uint16_t colormap[256]; // color palette temp -> color

bool autoScale = true;
float fixedMin = 20.0;
float fixedMax = 35.0;

void setup() {
  Serial.begin(9600);
  
  // init I2C
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  Wire.setClock(400000); // 400kHz
  
  // init thermal camera
  if (!mlx.begin(MLX90640_I2CADDR_DEFAULT, &Wire)) {
    Serial.println("No MLX90640 found!");
    while (1) delay(10);
  }
  
  mlx.setRefreshRate(MLX90640_4_HZ);
  
  // init TFT display
  tft.init();
  tft.setRotation(0); // portrait
  tft.fillScreen(TFT_BLACK);
  
  // set backlight
  pinMode(LCD_LED_PIN, OUTPUT);
  digitalWrite(LCD_LED_PIN, HIGH);
  
  generateColormap();
}

void loop() {
  if (mlx.getFrame(frame) != 0) { // read frame
    Serial.println("No frame data");
    delay(500);
    return;
  }
  
  // find min and max temperatures for auto-scaling
  float minTemp = 100;
  float maxTemp = 0;
  
  if (autoScale) {
    for (int i = 0; i < 32 * 24; i++) {
      if (frame[i] > 0 && frame[i] < 100) { // filter invalid readings
        minTemp = min(minTemp, frame[i]);
        maxTemp = max(maxTemp, frame[i]);
      }
    }
    
    // prevent too narrow temperature range
    if (maxTemp - minTemp < 5.0) {
      float midTemp = (maxTemp + minTemp) / 2;
      minTemp = midTemp - 2.5;
      maxTemp = midTemp + 2.5;
    }
  } else {
    // use fixed range
    minTemp = fixedMin;
    maxTemp = fixedMax;
  }
  
  displayThermalImage(minTemp, maxTemp);
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // show min and max temperatures
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.print("Min: ");
  tft.print(minTemp, 1);
  tft.print("C");
  
  tft.setCursor(10, 40);
  tft.print("Max: ");
  tft.print(maxTemp, 1);
  tft.print("C");
  
  delay(250);
}

void generateColormap() { // generate color palette
  for (int i = 0; i < 256; i++) {
    if (i < 64) {
      colormap[i] = tft.color565(0, 0, i * 4); // black to blue
    } 
    else if (i < 128) {
      colormap[i] = tft.color565(0, (i - 64) * 4, 255); // blue to cyan
    } 
    else if (i < 192) {
      colormap[i] = tft.color565((i - 128) * 4, 255, 255 - (i - 128) * 4); // cyan to yellow
    } 
    else {
      colormap[i] = tft.color565(255, 255 - (i - 192) * 4, 0); // yellow to red
    }
  }
}

void displayThermalImage(float minTemp, float maxTemp) { // display thermal image on TFT
  // calculate display size and scaling
  int displayWidth = tft.width();
  int displayHeight = tft.height();
  
  // scale pixel to display size
  int pixelWidth = displayWidth / 32;
  int pixelHeight = (displayHeight - 100) / 24; // reserve space for text
  
  // center image
  int offsetX = (displayWidth - (32 * pixelWidth)) / 2;
  int offsetY = 70; // space at top for text
  
  // display each thermal pixel
  for (int y = 0; y < 24; y++) {
    for (int x = 0; x < 32; x++) {
      float temp = frame[y * 32 + x];
      
      // map temp to color index
      int colorIndex;
      if (temp < minTemp) colorIndex = 0;
      else if (temp > maxTemp) colorIndex = 255;
      else colorIndex = map(temp * 100, minTemp * 100, maxTemp * 100, 0, 255);
      
      tft.fillRect( // one pixel
        offsetX + x * pixelWidth, 
        offsetY + y * pixelHeight, 
        pixelWidth, 
        pixelHeight, 
        colormap[colorIndex]
      );
    }
  }
  
  // scale bar
  int barHeight = 20;
  int barWidth = displayWidth - 40;
  int barX = 20;
  int barY = displayHeight - 30;
  
  for (int i = 0; i < barWidth; i++) {
    int colorIndex = map(i, 0, barWidth - 1, 0, 255);
    tft.drawFastVLine(barX + i, barY, barHeight, colormap[colorIndex]);
  }
  
  // color scale label
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  tft.setCursor(barX, barY - 15);
  tft.print(minTemp, 1);
  tft.print("C");
  
  tft.setCursor(barX + barWidth - 40, barY - 15);
  tft.print(maxTemp, 1);
  tft.print("C");
}