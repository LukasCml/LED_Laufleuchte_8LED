
/*
   Programm:          LED Laufleuchte mit 8 LED
   Letzte Änderung:   22.09.2020
   Programmierer:     LC

   Hardware:      Arduino UNO / 8 LED's an Pin 2,3,4,5,6,7,8,9 / Laufleuchte
*/

#include <OneButton.h>
OneButton button(10, false);

unsigned long letzteZeit;
int ledEinschaltDauer = 500;
bool statusPower = false;
int zeile = 0;
byte led[8] = {2, 3, 4, 5, 6, 7, 8, 9};
byte ledZustand[6][8] =
{
  {1, 0, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
};

void setup()
{
  for (byte i = 0; i < 8; i++)
  {
    pinMode (led[i], OUTPUT);
  }
  button.attachClick(StatusPowerSetzen);
}

void loop()
{
  button.tick();
  if (statusPower == true)
  {
    if ((millis() - letzteZeit) > ledEinschaltDauer)
    {
      for (byte i = 0; i < 8; i++)                          //Zeilen
      {
        digitalWrite(led[i], ledZustand[zeile][i]);
      }
      zeile++;
      if (zeile == 6)
      {
        zeile = 0;
      }
      letzteZeit = millis();
    }
  }
  else
  {
    for (int i = 0; i < 8; i++)
    {
      digitalWrite(led[i], LOW);
    }
  }
}


void StatusPowerSetzen()
{
  statusPower = !statusPower;
}
