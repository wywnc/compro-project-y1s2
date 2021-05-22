/*edited by Wanatchporn Silaruam 63070154
references: https://how2electronics.com/iot-ir-thermometer-using-mlx90614-esp8266-on-blynk/
            https://shopee.co.th/เซ็นเซอร์วัดอุณหภูมิร่างกายและวัตถุแบบไร้สัมผัส-GY-906-MLX90614-Non-touch-Infrared-Temperature-Sensor-Module-สำหรับ-Ardu-i.56441528.4541961868
            https://www.allnewstep.com/article/339/96-arduino-สอนวิธีใช้งาน-gy-906-เซนเซอร์-mlx90614-วัดอุณหภูมิแบบไร้สัมผัส*/

#include <Adafruit_GFX.h> //screen's lib
#include <Adafruit_SSD1306.h> //screen's lib
#include <stdint.h>
#include <Adafruit_MLX90614.h> //sensor's lib
 
#define OLED_RESET 4
 
Adafruit_SSD1306 display(OLED_RESET); //define display's lib as display
Adafruit_MLX90614 mlx = Adafruit_MLX90614(); //define sensor's lib as mlx
double calibrateC = 2.36;
double calibrateF = 36.248;
 
 
void setup()   
{                
  Serial.begin(57600); //transfer speed between board and pc via usb (board rate)  
  mlx.begin();  //start sensor
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  
  //buzzer
  pinMode(3, OUTPUT); //buzzer
  pinMode(2, INPUT); //switch c to f
  digitalWrite(3, LOW); //buzzer beep time
  delay(300);
  digitalWrite(3, HIGH);
}
 
 
void loop() 
{ 
  //digitalWrite(3, LOW);
    // Clear the buffer.
  display.clearDisplay(); //clear the screen
 
  // text display tests
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(28,10);
  if(digitalRead(2) == HIGH){
    display.print(mlx.readObjectTempC() + calibrateC);  //print celsius
    display.print(" C");
    display.display();
  }
  else{
    display.print(mlx.readObjectTempF() + calibrateF);  //print fahrenheit
    display.print(" F");
    display.display();
  }
  delay(2000);
 
}
