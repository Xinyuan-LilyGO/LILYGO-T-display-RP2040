# 🌟LilyGO T-Display RP2040🌟

## Arduino
Windows Users: Please do not use the Windows Store version of the actual Arduino application because it has issues detecting attached Pico boards. Use the "Windows ZIP" or plain "Windows" executable (EXE) download direct from https://arduino.cc. and allow it to install any device drivers it suggests. Otherwise the Pico board may not be detected. Also, if trying out the 2.0 beta Arduino please install the release 1.8 version beforehand to ensure needed device drivers are present. (See #20 for more details.)

Open up the Arduino IDE and go to File->Preferences.

In the dialog that pops up, enter the following URL in the "Additional Boards Manager URLs" field:

https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json

Go to Tools->Boards->Board Manager in the IDE

Type "pico" in the search box and select "Add":

### Quick start

1. Copy  **TFT_eSPI**  to the  **<C:\Users\Your User Name\Documents\Arduino\libraries>**  directory
2. Open **Arduino IDE,** find **TFT_eSPI** in the file and example, the **T-Display** factory test program is located at **TFT_eSPI -> FactoryTest**, you can also use other sample programs provided by TFT_eSPI
3 In the **Arduino IDE** tool options, select the development board  **Raspbreey Pi Pico**, Other keep the default
4. Hold down the BOOT button, click the reset button, and release the BOOT button after a delay of one second or after waiting for the computer to eject a new disk
5. Finally, click upload or drag the firmware to the new disk

-------------------------

1. 拷贝  **TFT_eSPI**  到  **<C:\Users\你的用户名\Documents\Arduino\libraries>**  目录内
2. 打开**ArduinoIDE** , 在文件，示例中找到**TFT_eSPI**, T-Display出厂测试程序位于**TFT_eSPI -> FactoryTest**,你也可以使用其他TFT_eSPI提供的示例程序
3. 在**Arduino IDE** 工具选项中 ， 开发板选择 **Raspbreey Pi Pico**,其它保持默认 
4. 按住BOOT按键,单击复位按键，延时一秒后或者等待电脑弹出新的磁盘后松开BOOT按键.
5. 最后可点击上传或者把固件拖拽到新磁盘中即可，勾号旁边的向右箭头

-------------------------

## MicroPython

1. 下载[Thonny Python IDE](https://github.com/thonny/thonny/releases/download/v3.3.5/thonny-3.3.5.exe)
2. 安装完毕后，需要点击在工具栏上，点击 运行->选择解释器，进入如下界面，选择**Raspberry Pi Pico**，下面的端口配置前需要先对 Pico 进行配置
3. 按下**BOOT**按键，单击一下**RES**，然后，回到Thonny Python IDE 将端口改成Pico所在的串口，如果没有找到可以点击**Install or update firmware**。
4. 依次写入即可看到LED在闪烁
~~~
from machine import Pin, Timer
led = Pin(25,Pin.OUT)
tim = Timer()
def tick(timer):
    global led
    led.toggle()
tim.init(freq=2.5, mode=Timer.PERIODIC, callback=tick)
~~~
5. 若需要保存到芯片，需要点击文件->另存为->rp2040

| Pins       | RP2040          |
| ---------- | --------------- |
| TFT Driver | ST7789(240*135) |
| TFT_MISO   | N/A             |
| TFT_MOSI   | 3               |
| TFT_SCLK   | 2               |
| TFT_CS     | 5               |
| TFT_DC     | 1               |
| TFT_RST    | 0               |
| TFT_BL     | 4               |
| PWR_ON     | 22              |
| BOTTON1    | 6               |
| BOTTON2    | 7               |
| RedLED     | 25              |