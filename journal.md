# 5/26/2025
Time spent: 2h
Researched different types of thermal cameras. I finally landed on the [Adafruit MLX90640 IR Thermal Camera Breakout](https://www.adafruit.com/product/4407).
I mainly chose this breakout because:
1. It came from a reputable manufacturer
2. It looked like it had decent quality
3. It communicates over i2c, making it really easy to work with.

For the screen, I decided on a generic 2.8" TFT LCD screen.
I also chose a ESP32-S3-WROOM-1 as the main MCU for this project.

# 5/28/2025
Time spent: 4h
I found [this](https://www.reddit.com/r/electronics/comments/a70koi/comment/ebzriyd/) lipo charger circuit on reddit. Since it outputs 5V
--
Spent quite a few hours looking up different lipo charger/discharge circuits. I've landed on charging a 18650 or similar battery using a MCP73871 and a MIC5504. Then spent a lot of time designing the schematic
