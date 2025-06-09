# Thermal Camera
This is my design of a cheap and affordable thermal camera (< $60, excl shipping)!. It utilizes the MLX90640 as the image sensor, and the esp32 to process and display the images on a TFT LCD screen.

I made this project because off the shelf thermal cameras are exuberantly expensive, and I need one to figure out if my PCBs are shorting.


The hardest part of this project so far was designing the battery charging circuit, as I needed to use multiple ICs to charge the battery, keep the voltage stable, and to keep the battery from overcharging.

# Screenshots
![image](https://github.com/user-attachments/assets/bfb91cfb-b7ea-49b0-bfd7-bb6e16e3c23b)
![image](https://github.com/user-attachments/assets/1add7e58-f31c-4946-83b4-e436eafc33ac)
![image](https://github.com/user-attachments/assets/81084bf6-0700-4935-8a9e-a61ce22c64c9)
![ApplicationFrameHost_TMCDneAYK6](https://github.com/user-attachments/assets/63a3391f-17fa-4976-af4c-8b1de6973849)
![ApplicationFrameHost_Y9mpmJQMrD](https://github.com/user-attachments/assets/495972b4-3cc5-4822-8513-aee2b1932eef)
![ApplicationFrameHost_UEK0gMYSmj](https://github.com/user-attachments/assets/efeb5221-4169-493a-9d29-9d4537862ef4)

# Firmware
You can find the firmware in the `thermal_camera` folder.

The firmware is written with the Arduino IDE. The ESP32 is used to read the thermal camera and display the images on the TFT LCD screen.

## Firmware Setup
1. Open the Arduino IDE.
2. Install the TFT_eSPI library and MLX90640 library by Adafruit.
3. Create a thermal_camera.h file in `C:\Users\YourUsername\Documents\Arduino\libraries\TFT_eSPI\User_Setups`
4. Paste in the following code:
```c
#define ILI9341_DRIVER
#define TFT_WIDTH 240 
#define TFT_HEIGHT 320 

#define TFT_MISO 8 
#define TFT_MOSI 6 
#define TFT_SCLK 5 
#define TFT_CS 15 
#define TFT_DC 4 
#define TFT_RST 16 
#define TFT_BL 7 

#define TOUCH_CS 10

#define SPI_FREQUENCY 40000000
```
5. Open `C:\Users\YourUsername\Documents\Arduino\libraries\TFT_eSPI\User_Setup_Select.h`
6. Add the line `#include <User_Setups/thermal_camera.h>` to the file under User_Setup.h
7. Compile and upload the firmware to the ESP32.

# BOM
The total cost of the project is about $86 USD: ([Spreadsheet](https://docs.google.com/spreadsheets/d/1PjPY5GV_mC4sFPF-p1Rz1wbnOWLJnwNhDzCwLhk1jFM/edit?usp=sharing))
![image](https://github.com/user-attachments/assets/87b91846-bc1c-4bb3-9cc9-d8c753890469)

