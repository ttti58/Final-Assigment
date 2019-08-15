#include "Usart.h"

void USART_Init(){
  USART->BRR1 = 0x68;
  USART->BRR2 = 0x03; //9600 baud
  USART->CR1 &= ~((1<<4)|(1<<5)); //8 data bit + USART enable
  USART->CR3 &= ~(3<<4);
  
  USART->CR2 |= (1<<3); //TxEN
  USART->CR2 |= (1<<5); //Rx Irq EN
  USART->CR2 |= (1<<2); //RxEN
}

void USART_Transmit(char data){
  while (!(USART->SR & (1<<7)));
  USART->DR = data;
}

void USART_SendString(char *data){
  register unsigned i = 0;
  while(data[i]){
    USART_Transmit(data[i]);
    i++;
  }
}

