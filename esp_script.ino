#define LED 23
#include "BluetoothSerial.h"

BluetoothSerial ESP_BT; 

int incoming;
int on_off = 0;

void setup() {
  Serial.begin(9600);
  ESP_BT.begin("ESP32_LED_Control");
  Serial.println("соединение выполнено");

  pinMode (LED, OUTPUT);
}

void loop() {
  
  if (ESP_BT.available()) 
  {
    incoming = ESP_BT.read(); 
    Serial.print("получено:"); Serial.println(incoming);

    if (incoming == 49)
        {
          ESP_BT.println(on_off);
          switch(on_off){
              case 0:
                digitalWrite(LED, HIGH);
                on_off = 1;
                break;
              case 1:
                digitalWrite(LED, LOW);
                on_off = 0;
                break;  
          }
          
        }
       
  }
  delay(20);
}
