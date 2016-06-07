#include "ds18b20.h"

/**************************************
��λDS18B20,������豸�Ƿ����
**************************************/
void DS18B20_Rst()
{
    
        digitalWrite( DSBPIN, LOW );                    
        delayMicroseconds(750);             
        digitalWrite( DSBPIN, HIGH );                    
        delayMicroseconds(15);                 
}

//�ȴ�DS18B20�Ļ�Ӧ
//����1:δ��⵽DS18B20�Ĵ���
//����0:����
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

//��DS18B20��ȡһ��λ
//����ֵ��1/0
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
//��DS18B20��ȡһ���ֽ�
//����ֵ������������
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
//дһ���ֽڵ�DS18B20
//dat��Ҫд����ֽ�
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


//��ʼ�¶�ת��
void DS18B20_Start(void) 
{   		
				               
    DS18B20_Rst();	   
	  DS18B20_Check();	 
    DS18B20_Write_Byte(0xcc);	// skip rom
    DS18B20_Write_Byte(0x44);	// convert
} 

//��ds18b20�õ��¶�ֵ
//���ȣ�0.1C
//����ֵ���¶�ֵ ��-550~1250�� 
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
        temp=0;					//�¶�Ϊ��  
    }else temp=1;				//�¶�Ϊ��	  	  
    tem=TH; 					//��ø߰�λ
    tem<<=8;    
    tem+=TL;					//��õװ�λ
    tem=(float)tem*0.625;		//ת��     
	if(temp)return tem; 		//�����¶�ֵ
	else return -tem; 
	 
}