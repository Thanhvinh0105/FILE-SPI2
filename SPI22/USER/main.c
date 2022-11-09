#include "stm32f10x.h"             
#include "stm32f10x_gpio.h"       
#include "stm32f10x_rcc.h"        
#include <stm32f10x_spi.h>

void delay_ms(uint16_t x);
void taoxung(void);
void kbspi( void);
 void chspi(void);
void led( void);
void spi_cmd(void);
int main(){
	  taoxung();
	  led();
		chspi();
		kbspi();
		spi_cmd();
	while(1){
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		SPI_I2S_SendData(SPI2,0x50);
		while ( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY)== SET)
			{
	   }
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
	delay_ms(500);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	delay_ms (500);}
}
void delay_ms(uint16_t x ){
	uint16_t s,d;
	for(s=0; s< x; s++){
		for(d=0; d < 0xAFF; d++);
	}
}
void taoxung(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
}
void led(void){
	GPIO_InitTypeDef led;
	led.GPIO_Pin = GPIO_Pin_13;
	led.GPIO_Mode = GPIO_Mode_Out_PP;
	led.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&led);
}
void kbspi(void){
	GPIO_InitTypeDef spi;
	// khai bao chan pb12_ SPI2_NSS;
	spi.GPIO_Pin = GPIO_Pin_12;
	spi.GPIO_Mode = GPIO_Mode_Out_PP;
	spi.GPIO_Speed = GPIO_Speed_50MHz;
	// khai bao chan pb13_ SPI3_SCK;
	spi.GPIO_Pin = GPIO_Pin_13;
	spi.GPIO_Mode = GPIO_Mode_AF_PP;
	spi.GPIO_Speed = GPIO_Speed_50MHz;
	// khai bao chan pb14_ SPI3_MISO;
	spi.GPIO_Pin = GPIO_Pin_14;
	spi.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	spi.GPIO_Speed = GPIO_Speed_50MHz;
	// khai bao chan pb15_ SPI3_sImO;
	spi.GPIO_Pin = GPIO_Pin_14;
	spi.GPIO_Mode = GPIO_Mode_AF_PP;
	spi.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&kbspi);
}
void chspi(void){
	SPI_InitTypeDef spi2;
	spi2.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
	spi2.SPI_CPHA = SPI_CPHA_1Edge;
	spi2.SPI_CPOL = SPI_CPOL_Low;
	spi2.SPI_CRCPolynomial = SPI_CRCPR_CRCPOLY;
	spi2.SPI_DataSize = SPI_DataSize_8b;
	spi2.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	spi2.SPI_FirstBit = SPI_FirstBit_LSB;
	spi2.SPI_Mode = SPI_Mode_Master;
	spi2.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI2,&spi2);
	}
 void spi_cmd(void){
	SPI_Cmd(SPI2,ENABLE);
	}
	
	

