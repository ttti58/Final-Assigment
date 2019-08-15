#include "SPI.h"

void SPI_SlaveInit(void){
  PB->DDR |= (1<<MISO1);
  PB->CR1 |= (1<<MISO1);
  
  PB->DDR &= ~((1<<MOSI1)|(1<<SCK1));
  PB->CR1 |= (1<<MOSI1)|(1<<SCK1);
  
  //PA->DDR |= (1<<MISO2);
  //PA->CR1 |= (1<<MISO2);
  
  //PC->DDR &= ~((1<<MOSI2)|(1<<SCK2));
  //PC->CR1 |= ((1<<MOSI2)|(1<<SCK2));
  
  SPI->CR1 &= ~(1<<MSTR);
  SPI->CR1 |= (1<<CPOL);
  
  SPI->CR2 |= (1<<BDM);
  SPI->CR2 &= ~(1<<BDOE);
  
  SPI->ICR |= (1<<RXIE);
  
  SPI->CR1 |= (1<<SPE);
}
void SPI_MasterInit(void){
  PB->DDR |= ((1<<MOSI1)|(1<<SCK1));
  PB->CR1 |= (1<<MOSI1)|(1<<SCK1);
  
  PB->DDR &= ~(1<<MISO1);
  //PB->CR1 |= (1<<MISO1);
  
  //PC->DDR |= ((1<<MOSI2)|(1<<SCK2));
  //PC->CR1 |= ((1<<MOSI2)|(1<<SCK2));
  
  //PA->DDR &= ~(1<<MISO2);
  //PA->CR1 |= (1<<MISO2);
  SPI->CR1 &= ~(7<<BR);
  SPI->CR1 |= (2<<BR);
  
  SPI->CR1 |= (1<<CPOL);
  SPI->CR1 |= (1<<CPHA);
  
  SPI->CR2 |= (1<<BDM);
  SPI->CR2 |= (1<<BDOE);
  
  SPI->CR1 |= (1<<MSTR);
  SPI->CR1 |= (1<<SPE);
}

void SPI_Transmit(char data){
  //SPI->CR1 |= (1<<SPE);
  while(!(SPI->SR & (1<<TXE)));
  SPI->DR = data;
  //while(SPI->SR & (1<<BSY));
  //SPI->CR1 &= ~(1<<SPE);
}