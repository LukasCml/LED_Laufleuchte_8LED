/*
   Programm:          LED Laufleuchte mit 8 LED
   Letzte Änderung:   18.09.2020
   Programmierer:     LC

   Hardware:      Arduino UNO / 8 LED's an Pin 2,3,4,5,6,7,8,9 / Laufleuchte
*/

byte led[8] = {2, 3, 4, 5, 6, 7, 8, 9};


void setup()
{
  for (byte i = 0; i < 9; i++)
  {
    pinMode (led[i], OUTPUT);
  }
}

void loop()
{
  for (byte i = 0; i < 9; i++)
  {
    digitalWrite(led[i], HIGH);
    delay(150);
  }
  for (byte i = 8; i < 9; i--)
  {
    digitalWrite(led[i], LOW);
    delay(150);
  }
}
