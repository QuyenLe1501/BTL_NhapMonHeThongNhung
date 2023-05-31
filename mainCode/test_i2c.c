///**************************************************************************//**
// * @file     CTR_I2C.c
// * @Deverloper	lochoang360			    
// *           
// * @version  V0.1
// * @date     14. Oct 2016
// *
// * @note
// *
// ******************************************************************************/
///* Copyright (c) 2016 LINH KIEN 3M*/

//#include "test_i2c.h"
//#include "delay.h"

//void CTR_I2C_GPIO_Init(void)
//{
//  GPIO_InitTypeDef gpioInit;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
//	gpioInit.GPIO_Mode = GPIO_Mode_Out_OD;
//	gpioInit.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
//	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
//	
//	GPIO_Init(GPIOB, &gpioInit);
//}
///*delay for I2C*/
////void CTR_I2C_Delay(void)
////{
////		
////   delay_us(30);
////}

////void CTR_I2C_Delay5ms(void)
////{
////		
////   Delay_Ms(5);
////}

//void CTR_I2C_Delay(void)
//{
//		
//   uint8_t i=30; 
//   while(i) 
//   { 
//     i--; 
//   }  
//}

//void CTR_I2C_Delay5ms(void)
//{
//		
//   int i=5000;  
//   while(i) 
//   { 
//     i--; 
//   }  
//}

//bool CTR_I2C_Start(void)
//{
//	SCL_H;
//	delay_us(3);
//	SDA_H;
//	delay_us(3);
//	//CTR_I2C_Delay();
//	//if(!SDA_read)return false;	
//	SDA_L;
//	delay_us(3);
//	//CTR_I2C_Delay();
//	//if(SDA_read) return false;	
//	SCL_L;
//	delay_us(3);
//	//CTR_I2C_Delay();
//	return true;
//}

//void CTR_I2C_Stop(void)
//{
//	SDA_L;
//	delay_us(3);
//	SCL_H;
//	delay_us(3);
//	SDA_H;
//	delay_us(3);
////	SCL_L;
////	CTR_I2C_Delay();
////	SDA_L;
////	CTR_I2C_Delay();
////	SCL_H;
////	CTR_I2C_Delay();
////	SDA_H;
////	CTR_I2C_Delay();
//} 

//void CTR_I2C_Ack(void)
//{	
//	SCL_L;
//	CTR_I2C_Delay();
//	SDA_L;
//	CTR_I2C_Delay();
//	SCL_H;
//	CTR_I2C_Delay();
//	SCL_L;
//	CTR_I2C_Delay();
//}   

//void CTR_I2C_NoAck(void)
//{	
//	SCL_L;
//	CTR_I2C_Delay();
//	SDA_H;
//	CTR_I2C_Delay();
//	SCL_H;
//	CTR_I2C_Delay();
//	SCL_L;
//	CTR_I2C_Delay();
//} 

//bool CTR_I2C_WaitAck(void) 	 
//{
//	SCL_L;
//	CTR_I2C_Delay();
//	SDA_H;			
//	CTR_I2C_Delay();
//	SCL_H;
//	CTR_I2C_Delay();
//	if(SDA_read)
//	{
//      SCL_L;
//	  CTR_I2C_Delay();
//      return false;
//	}
//	SCL_L;
//	CTR_I2C_Delay();
//	return true;
//}

//uint8_t CTR_I2C_SendByte(uint8_t u8Data) 
//{
////    uint8_t i=8;
////    while(i--)
////    {
////        SCL_L;
////        CTR_I2C_Delay();
////      if(SendByte&0x80)
////        SDA_H;  
////      else 
////        SDA_L;   
////        SendByte<<=1;
////        CTR_I2C_Delay();
////		SCL_H;
////        CTR_I2C_Delay();
////    }
////    SCL_L;
//	uint8_t i;
//	uint8_t u8Ret;
//	
//	for (i = 0; i < 8; ++i) {
//		if (u8Data & 0x80) {
//			SDA_H;
//		} else {
//			SDA_L;
//		}
//		delay_us(3);
//		SCL_H;
//		delay_us(5);
//		SCL_L;
//		delay_us(2);
//		u8Data <<= 1;
//	}
//	
//	SDA_H;
//	delay_us(3);
//	SCL_H;
//	delay_us(3);
//	if (SDA_read) {
//		u8Ret = 0;
//	} else {
//		u8Ret = 1;
//	}
//	delay_us(2);
//	SCL_L;
//	delay_us(5);
//	
//	return u8Ret;
//}  

//unsigned char CTR_I2C_RadeByte(void)  
//{ 
//    uint8_t i=8;
//    uint8_t ReceiveByte=0;

//    SDA_H;				
//    while(i--)
//    {
//      ReceiveByte<<=1;      
//      SCL_L;
//      CTR_I2C_Delay();
//	  SCL_H;
//      CTR_I2C_Delay();	
//      if(SDA_read)
//      {
//        ReceiveByte|=0x01;
//      }
//    }
//    SCL_L;
//    return ReceiveByte;
//} 

//bool CTR_Single_Write(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data)		     
//{
//  	if(!CTR_I2C_Start())return false;
//    CTR_I2C_SendByte(SlaveAddress);   
//    if(!CTR_I2C_WaitAck()){CTR_I2C_Stop(); return false;}
//    CTR_I2C_SendByte(REG_Address );   //
//    CTR_I2C_WaitAck();	
//    CTR_I2C_SendByte(REG_data);
//    CTR_I2C_WaitAck();   
//    CTR_I2C_Stop(); 
//    CTR_I2C_Delay5ms();
//    return true;
//}
//int8_t test =0;
//unsigned char CTR_Single_Read(unsigned char SlaveAddress,unsigned char REG_Address)
//{   unsigned char REG_data;     	
//	if(!CTR_I2C_Start())return false;
//    CTR_I2C_SendByte(SlaveAddress); 
//    if(!CTR_I2C_WaitAck()){CTR_I2C_Stop();test=1; return false;}
//    CTR_I2C_SendByte((uint8_t) REG_Address);  
//    CTR_I2C_WaitAck();
//    CTR_I2C_Start();
//    CTR_I2C_SendByte(SlaveAddress+1);
//    CTR_I2C_WaitAck();

//	REG_data= CTR_I2C_RadeByte();
//    CTR_I2C_NoAck();
//    CTR_I2C_Stop();    
//	return REG_data;

//}			
///*end of file*/