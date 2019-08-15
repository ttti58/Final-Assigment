#include "stm8.h"

void main( void )
{

}

#pragma vector = 11
__interrupt void Button_Stop(void){
  SPI_Transmit('s'); //send char "s"
  EXTI->SR1 |= (1<<1);
}

#pragma vector = 12
__interrupt void Button_Cancel(void){
  SPI_Transmit('c');
  EXTI->SR1 |= (1<<1);
}

#pragma vector = 13
__interrupt void Button1(void){
  PE->ODR |= (1<<7);//on led_slave_1 led green
  SPI_Transmit('a');
  
  EXTI->SR1 |= (1<<1);
}

#pragma vector = 14
__interrupt void Button2(void){
  PC->ODR |= (1<<7);//on led_slave_1 led green
  SPI_Transmit('b');
  
  EXTI->SR1 |= (1<<1); 
}