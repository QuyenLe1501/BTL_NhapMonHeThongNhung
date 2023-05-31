#include "stm32f10x.h"
#include "i2c_lcd.h"
#include "delay.h"
#include "i2c.h"
#include "i2c_mpu6050.h"
#include "test_i2c.h"
#include "stdio.h"
#include "interrupt.h"

uint32_t i = 0;
float * CTR_MPU6050_getvalue;
char CTR_datasend[32];
uint8_t logic_led = 0;
int count = 0;
float gtb_X = 0;
float G_sum = 0, Gx = 0, Gz = 0;
int start =0;
uint32_t index1 =0;
int main(void)

{
	GPIO_InitTypeDef gpioInit;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	gpioInit.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpioInit);
	
	
	delay_init();
	interrupt_init(RCC_APB2Periph_GPIOB, GPIO_Pin_0, GPIO_PortSourceGPIOB, GPIO_PinSource0, 
	EXTI_Line0, EXTI0_IRQn, 0x01);
	
	interrupt_init(RCC_APB2Periph_GPIOB, GPIO_Pin_1, GPIO_PortSourceGPIOB, GPIO_PinSource1, 
	EXTI_Line1, EXTI1_IRQn, 0x00);
	
	I2C_MPU6050_Setup();
  I2C_MPU6050_Init();
	
	I2C_LCD_Setup();
	I2C_LCD_Init();
	I2C_LCD_BackLight(1);
	I2C_LCD_Clear();
	sprintf(CTR_datasend,"Buoc chan : %d", count);
	I2C_LCD_Puts(CTR_datasend);
	
	while (1) {
		logic_led = read_interrupt();
		if (logic_led == 1)
		{
			GPIO_ResetBits(GPIOC, GPIO_Pin_14);
			I2C_MPU6050_Setup();
			CTR_MPU6050_getvalue = CTR_READ_ACCEL_MPU3050();
			
			
			//---------- Xu ly du lieu dua tren gia toc truc x và z
			
			G_sum = sqrt(pow(CTR_MPU6050_getvalue[0], 2) + pow(CTR_MPU6050_getvalue[2],2));
			
			if (start == 0 && G_sum < 0.99 )
			{
				Gx = CTR_MPU6050_getvalue[0];// luu giá tr? Gx và Gz khi chua di chuy?n
				Gz = CTR_MPU6050_getvalue[2];
			}
			
			
			if (start == 0 && 0.99 <= G_sum && G_sum <= 2)
			{
				start =1;
			}
			
			if (start == 1 && 0.99 <= G_sum && G_sum <= 2 )
			{
				index1 ++;
				gtb_X = sqrt(pow(CTR_MPU6050_getvalue[0] - Gx, 2) + pow(CTR_MPU6050_getvalue[2] - Gz,2)) + gtb_X;
				
			}
			
			if ( start == 1 && G_sum < 0.99 )
			{
				gtb_X = gtb_X / index1 ;

				if (gtb_X >= 0.2 && index1 >= 45 )
				{
					count ++;
					I2C_LCD_Setup();
					I2C_LCD_Clear();
					sprintf(CTR_datasend,"Buoc chan : %d", count);
					I2C_LCD_Puts(CTR_datasend);
					
				}
				index1 = 0;
				gtb_X=0;
				start = 0;
			}
			
			// -------------------------------------
			
			i++;
			Delay_Ms(1);
			
			
			if ( i == 500)
			GPIO_SetBits(GPIOC, GPIO_Pin_13);
			if (i == 1000){
				GPIO_ResetBits(GPIOC, GPIO_Pin_13);
				
				I2C_LCD_Setup();
				sprintf(CTR_datasend,"Z=%.4f ",CTR_MPU6050_getvalue[2]);
				I2C_LCD_NewLine();
				I2C_LCD_Puts(CTR_datasend);
				
				i = 0;
			}
		}
		else
		{
			GPIO_SetBits(GPIOC, GPIO_Pin_14);
			GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		}
		
	}
}
