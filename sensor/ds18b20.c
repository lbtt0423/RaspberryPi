#include "ds18b20.h"

/**************************************
复位DS18B20,并检测设备是否存在
**************************************/
void DS18B20_Rst()
{
    
        digitalWrite( DSBPIN, LOW );                    
        delayMicroseconds(750);             
        digitalWrite( DSBPIN, HIGH );                    
        delayMicroseconds(15);                 
}

//等待DS18B20的回应
//返回1:未检测到DS18B20的存在
//返回0:存在
uint8_t DS18B20_Check(void) 	   
{   
	uint8_t retry=0;
    while ((digitalRead( DSBPIN ))&&retry<200)
	{
		retry++;
		delayMicroseconds(1);
	};	 
	if(retry>=200)
		{
			printf("DS18B20 is not exist\n");
			return 1;
		}
	else retry=0;
   while (!(digitalRead( DSBPIN ))&&retry<240)
	{
		retry++;
		delayMicroseconds(1);
	};
	if(retry>=240)
		{
			printf("DS18B20 is not exist\n"); 
		  return 1;
		};  
	return 0;
}

//从DS18B20读取一个位
//返回值：1/0
uint8_t DS18B20_Read_Bit(void) 	 
{
    uint8_t data;

   digitalWrite( DSBPIN, LOW ); 
	 delayMicroseconds(2);
   digitalWrite( DSBPIN, HIGH ); 

	delayMicroseconds(12);
	if((digitalRead( DSBPIN )))data=1;
    else data=0;	 
    delayMicroseconds(50);           
    return data;
}
//从DS18B20读取一个字节
//返回值：读到的数据
uint8_t DS18B20_Read_Byte(void)     
{        
    uint8_t i,j,dat;
    dat=0;
	for (i=1;i<=8;i++) 
	{
        j=DS18B20_Read_Bit();
        dat=(j<<7)|(dat>>1);
    }						    
    return dat;
}
//写一个字节到DS18B20
//dat：要写入的字节
void DS18B20_Write_Byte(uint8_t dat)     
 {             
    uint8_t j;
    uint8_t testb;
    for (j=1;j<=8;j++) 
	{
        testb=dat&0x01;
        dat=dat>>1;
        if (testb) 
        {
            digitalWrite( DSBPIN, LOW );
            delayMicroseconds(2);                            
            digitalWrite( DSBPIN, HIGH );
            delayMicroseconds(60);             
        }
        else 
        {
            digitalWrite( DSBPIN, LOW );	// Write 0
            delayMicroseconds(60);             
            digitalWrite( DSBPIN, HIGH );
            delayMicroseconds(2);                          
        }
    }
}


//开始温度转换
void DS18B20_Start(void) 
{   		
				               
    DS18B20_Rst();	   
	  DS18B20_Check();	 
    DS18B20_Write_Byte(0xcc);	// skip rom
    DS18B20_Write_Byte(0x44);	// convert
} 

//从ds18b20得到温度值
//精度：0.1C
//返回值：温度值 （-550~1250） 
short DS18B20_Get_Temp(void)
{
    uint8_t temp;
    uint8_t TL,TH;
	 short tem;
    DS18B20_Start();  			// ds1820 start convert
    DS18B20_Rst();
    
    DS18B20_Check();
   	 
    DS18B20_Write_Byte(0xcc);	// skip rom
    DS18B20_Write_Byte(0xbe);	// convert	    
    TL=DS18B20_Read_Byte(); 	// LSB   
    TH=DS18B20_Read_Byte(); 	// MSB  
	    	  
    if(TH>7)
    {
        TH=~TH;
        TL=~TL; 
        temp=0;					//温度为负  
    }else temp=1;				//温度为正	  	  
    tem=TH; 					//获得高八位
    tem<<=8;    
    tem+=TL;					//获得底八位
    tem=(float)tem*0.625;		//转换     
	if(temp)return tem; 		//返回温度值
	else return -tem; 
	 
}