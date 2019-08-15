#ifndef USART1
#define USART1
#include <stdint.h>

typedef struct{
  uint8_t SR;
  uint8_t DR;
  uint8_t BRR1;
  uint8_t BRR2;
  uint8_t CR1;
  uint8_t CR2;
  uint8_t CR3;
  uint8_t CR4;
  uint8_t CR5;
  uint8_t GTR;
  uint8_t PSCR;
 }USART_Type;

#define USART ((volatile USART_Type*)0x5230)

void USART_Init(void);
void USART_Transmit(char data);


#endif