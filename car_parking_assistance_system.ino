#define buzzer 12
#define Trigpin 18
#define echopin 5
#define Screenwidth 128
#define screenheight 32
#define oledreset -1
#include<Wire.h>
#include<Adafruit_SSD1306.h>
Adafruit_SSD1306 display(Screenwidth,screenheight,&Wire,oledreset);
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  pinMode(Trigpin,OUTPUT);
  pinMode(echopin,INPUT);
   Wire.begin(21,22);
  if (!display.begin(SSD1306_SWITCHCAPVCC,0x3C))
  {
    Serial.println("OLED not found .check wiring!");
    for(;;);
    }
  

}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(Trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin,LOW);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10,0);
  delayMicroseconds(2);
  long duration=pulseIn(echopin,HIGH);
  float distance=(duration * 0.0343) / 2;
  if(distance<=6)
  {
    display.clearDisplay();
    digitalWrite(buzzer,HIGH);
    display.println("Alert! Stop");
    display.display();
  }
  else
  {
    display.clearDisplay();
    digitalWrite(buzzer,LOW);
    display.println("park here!distance:");
    display.println(distance);
    delayMicroseconds(10);
    display.display();
  }
   delay(10);
}
