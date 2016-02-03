#include <SHT1x.h>
#include <stdio.h>
#include <stlib.h>
#include <string.h>

#define dataPin 3
#define clockPin 4
#define STX 0x02
#define ETX 0x03

SHT1x sht1x(dataPin, clockPin);

char buffer[30];
char t[10];
char h[10];
float tmp;
float hmd;
int angle, i;
char tempChar;

void setup() {

  Serial.begin(115200);    // start serial at 9600 baud// -- DRV_STR_PIN --
  Serial.setTimeout(100);
  delay(1000);
}

void loop() {


  tmp = sht1x.readTemperatureC();
  hmd = sht1x.readHumidity();   
  dtostrf(tmp, 6, 2, t);
  dtostrf(hmd, 6, 2, h);
  sprintf(buffer, "%s/%s",  t, h);
  Serial.write(STX);
  Serial.write(buffer, strlen(buffer)+1);
  Serial.write(ETX);
  delay(200);
}





