#include "M5Atom.h"
    
uint8_t DisBuff[0];

void setBuff(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata)
{
    DisBuff[0] = 0x05;
    DisBuff[1] = 0x05;
    for (int i = 0; i < 25; i++)
    {
        DisBuff[2 + i * 3 + 0] = Rdata;
        DisBuff[2 + i * 3 + 1] = Gdata;
        DisBuff[2 + i * 3 + 2] = Bdata;
    }
}

void change(int i)
{
    switch(i)
    {
      case 0:
          setBuff(0x40, 0x00, 0x00);
          break;
      case 1:
          setBuff(0x00, 0x40, 0x00);
          break;
      case 2:
          setBuff(0x00, 0x00, 0x40);
          break;
      default:
          break;
    }
    M5.dis.displaybuff(DisBuff);    
}





void setup()
{
    M5.begin(true, false, true);
    delay(10);
    setBuff(0x20, 0x20, 0x20);
    M5.dis.displaybuff(DisBuff);
}

int color = 0;

void loop()
{
    if (M5.Btn.wasPressed())
    {
      change(color);
      color++;
      if (color >= 3)
      {
          color = 0;  
      }
    }
    
    delay(50);
    M5.update();
}
