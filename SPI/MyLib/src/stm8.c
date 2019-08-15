#include "Stm8.h"


void delay_ms(unsigned int millisecond){
  register unsigned int i = 0;
  while(i < millisecond*100){
    i++;
  }
}

void SYSCLK_Init(){
  CLK->DIVR = 0x00; //SYSCLK / 1
  CLK->ICKR |= (1<<0); //HSI = 16 MHz
  while (CLK->SCSR != 0x01);
  CLK->PCKENR1 |= (3<<4);
}

void LCDCLK_Init(){
  CLK->PCKENR2 |= (1<<3); //LCD
  CLK->CRTCR |= (1<<4); //LSE for LCD
  while(!(CLK->ECKR & (1<<3)));
}

void PCKENR1_Init(uint8_t data){
  CLK->PCKENR1 |= (data);
}

void PCKENR2_Init(uint8_t data){
  CLK->PCKENR2 |= (data);
}


void Kit_Init(bool isIrq){
  PE->DDR |= (1<<7);
  PE->CR1 |= (1<<7);
  
  PC->DDR |= (1<<7);
  PC->CR1 |= (1<<7);
  
  PC->DDR &= ~(1<<1);
  PC->CR1 |= (1<<1); //pull-up
  if (isIrq){
    PC->CR2 |= (1<<1);
    EXTI->CR1 |= (1<<3);
    ITC->SPR3 |= (3<<2);
  }
  
}