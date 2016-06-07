#include "ps2.h"

void ps2_init()
{
		pinMode(DATI, OUTPUT);
		pinMode(SWD, INPUT);
		pinMode(CS,  OUTPUT);
		pinMode(CLK, OUTPUT);
		pinMode (LED,OUTPUT);
		pinMode (DATO, INPUT);
		
}
 
uint8_t GetValue0832(uint8_t Channel)
{
 {
      uint8_t i,test,adval,dat;
     adval = 0x00;
     test = 0x00;
    digitalWrite( CLK, LOW );       //初始化
     digitalWrite(DATI,HIGH );
     delayMicroseconds(15);
    digitalWrite( CS, LOW );
     delayMicroseconds(15);
    digitalWrite( CLK,HIGH );
    delayMicroseconds(15);
   if ( Channel == 0x00 )      //通道选择
   {
      digitalWrite( CLK, LOW );
       digitalWrite(DATI,HIGH );      //通道0的第一位
        delayMicroseconds(15);
      digitalWrite( CLK,HIGH );
         delayMicroseconds(15);
       digitalWrite( CLK, LOW );
      digitalWrite(DATI , LOW );      //通道0的第二位
       delayMicroseconds(15);
      digitalWrite( CLK,HIGH );
       delayMicroseconds(15);
    } 
    else
    {
      digitalWrite( CLK, LOW );
      digitalWrite(DATI,HIGH );      //通道1的第一位
        delayMicroseconds(15);
       digitalWrite( CLK,HIGH );
        delayMicroseconds(15);
     digitalWrite( CLK, LOW );
      digitalWrite(DATI,HIGH );      //通道1的第二位
     delayMicroseconds(15);
     digitalWrite( CLK,HIGH );
      delayMicroseconds(15);
    }
     digitalWrite( CLK, LOW );
      digitalWrite(DATI,HIGH );
    for( i = 0;i < 8;i++ )      //读取前8位的值
    {
        delayMicroseconds(15);
       adval <<= 1;
       digitalWrite( CLK,HIGH );
        delayMicroseconds(15);
      digitalWrite( CLK, LOW );
       if ((digitalRead( DATO )))
          adval |= 0x01;
      else
          adval |= 0x00;
    }
     
       dat = adval;
       delayMicroseconds(15);
       digitalWrite(CS , HIGH );        //释放ADC0832
       digitalWrite(DATO , HIGH );
       digitalWrite( CLK,HIGH );
      return dat*2;
}

}