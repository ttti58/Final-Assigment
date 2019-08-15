#include "CLOCK.h"
#include "External.h"
#include "GPIO.h"
#include "Itc.h"
#include "Usart.h"
#include "SPI.h"
#include <stdint.h>
#include <stdbool.h>

#define IRQ     true
#define NOT_IRQ false

static volatile unsigned char recvData;

void delay_ms(unsigned int millisecond);
void SYSCLK_Init();
void Kit_Init(bool isIrq);
void LCDCLK_Init();
void PCKENR1_Init(uint8_t data);
void PCKENR2_Init(uint8_t data);
