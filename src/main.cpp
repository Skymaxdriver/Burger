
#include <Arduino.h>
#include <NIBOburger.h>
//Treibnix Abstandsensor korrekturen
#define lloff
#define rroff
#define loff +4
#define roff -5

int engineR, engineL;


void setup()
{
  NIBOburger.begin();
}

void states()
{
  Engine.setSpeed(256, 256);
  int l = SensorFL.get();
  int r = SensorFR.get();
  int ll = SensorFLL.get();
  int rr = SensorFRR.get();
  // Abstandsensoren Auslesen
  if (r+roff < 20&& l+loff < 20 && engineR <1024 && engineL < 1024)
  {
    NIBOburger.setLed(LED3, 1);
    engineR = 100;
    engineL = 100;
  }
  if (r+roff > 25 && l+loff > 25)
  {
    NIBOburger.setLed(LED3, 0);
    engineR = 0;
    engineL = 0;
  }
  if (rr < 20 && r+roff < 20&& l+loff < 20 && engineR <1024 && engineL < 1024)
  {
    NIBOburger.setLed(LED4, 0);
    engineR = 100;
  }
  if (rr > 25 && r+roff < 20&& l+loff < 20 && engineR <1024 && engineL < 1024)
  {
    NIBOburger.setLed(LED4, 1);
    engineR = 0;
  }
  if (ll < 10 && r+roff < 20&& l+loff < 20 && engineR <1024 && engineL < 1024)
  {
    NIBOburger.setLed(LED1, 0);
    engineL = 100;
  }
  if (ll > 15 && r+roff < 20&& l+loff < 20 && engineR <1024 && engineL < 1024)
  {
    NIBOburger.setLed(LED1, 1);
    engineL = 0;
  }
  //Finaly set engine speed;
  Engine.setSpeed(engineL, engineR);
}


void loop()
{
  states();
  NIBOburger.setLed(LED2, 1);
  //delay(1000);
}
