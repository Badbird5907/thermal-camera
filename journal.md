**Total Time: 34h**

# 5/26
Time spent: 2h
Researched different types of thermal cameras. I finally landed on the [Adafruit MLX90640 IR Thermal Camera Breakout](https://www.adafruit.com/product/4407).
I mainly chose this breakout because:
1. It came from a reputable manufacturer
2. It looked like it had decent quality
3. It communicates over i2c, making it really easy to work with.

For the screen, I decided on a generic 2.8" TFT LCD screen.
I also chose a ESP32-S3-WROOM-1 as the main MCU for this project.

# 5/28
Time spent: 4h
I found [this](https://www.reddit.com/r/electronics/comments/a70koi/comment/ebzriyd/) lipo charger circuit on reddit. Since it outputs 5V
--
Spent quite a few hours looking up different lipo charger/discharge circuits. I've landed on charging a 18650 or similar battery using a MCP73871 and a MIC5504. Then spent a lot of time designing the schematic

# 5/29 & 5/30
Time spent: 5h

I spent a lot of time investigating different IR sensor modules. I finally landed on the MLX90640, which is a cheap thermal sensor with a resolution of 32x24 pixels. I then spent a lot of time designing the schematic.
I'm also looking into turning this into a module that plugs into an android phone.

# 5/31
Time spent: 3h

Finalized schematic design and started work on PCB routing. I might attempt to rip out everything battery charging related and reimplement it

# 6/1
Time spent: 3h

Spent a lot of time routing the pcb

# 6/2
Time spent: 5h
Routing pcb and fixing issues with schematic.

# 6/3
Time spent: 2h
Finializing pcb, added fallback pins to the power in

# 6/4
Time spent: 5h
Finished the PCB, sourced parts. Finished the case CAD.
![ApplicationFrameHost_UEK0gMYSmj](https://github.com/user-attachments/assets/2054bd38-e86a-48ae-a2cf-0893621192db)
![ApplicationFrameHost_Y9mpmJQMrD](https://github.com/user-attachments/assets/5d0aea0a-1581-4210-8405-b96ca57c3fa6)
![ApplicationFrameHost_TMCDneAYK6](https://github.com/user-attachments/assets/4597f4c2-b643-4aba-a8d6-1164c3917146)
![kicad_72Akr1wMqy](https://github.com/user-attachments/assets/3c58292e-0594-4c71-914f-dc51813e364f)
![kicad_yXDkx9Mt58](https://github.com/user-attachments/assets/9376405d-6afe-4d93-b60b-b3e33d982e1e)
![kicad_kI7ghjKoyS](https://github.com/user-attachments/assets/3129d40e-ae51-465a-864d-077ebcc0ca00)

# 6/11 - 6/13
Time spent: 2h
Reworked bom to use some parts from aliexpress. Also reworked some traces on the PCB and moved the battery connector to the top left. I've also added and remove parts from the digikey bom that I forgot.

# 7/8

Time spent: 5h

Parts arrived, I reflowed all the parts on the board, and spent forever debugging both software and hardware. Ended up having to bodge wire some pins, but it works!
I also had to go into the Arduino TFT library to get it to work with my ESP32.

![20250709_015518](https://github.com/user-attachments/assets/3794a1af-1700-4b59-b9cb-f46aea11919b)
![20250709_021239](https://github.com/user-attachments/assets/625bd81a-f133-455e-ac67-6502b244b54d)
![20250709_021320](https://github.com/user-attachments/assets/b472841b-db4c-4fbe-a878-2176fae16ff5)

