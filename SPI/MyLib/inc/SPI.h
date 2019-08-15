#ifndef SPI1
#define SPI1

#include <stdint.h>
#include "Gpio.h"

typedef struct{
  uint8_t CR1;
  uint8_t CR2;
  uint8_t ICR;
  uint8_t SR;
  uint8_t DR;
  uint8_t CRCPR;
  uint8_t RXCRCR;
  uint8_t TXCRCR;
}SPI_Type;

#define SPI ((volatile SPI_Type *)0x5200)

//CR1 bits
#define LSBFirst        7 
#define SPE             6
#define BR              3
#define MSTR            2
#define CPOL            1
#define CPHA            0

//CR2 bits
#define BDM             7
#define BDOE            6
#define CRCEN           5
#define CRCNext         4
#define RxOnly          2
#define SSM             1
#define SSI             0

//ICR bits
#define TXIE            7
#define RXIE            6
#define ERRIR           5
#define WKIE            4
#define TXDMAEN         1
#define MXDMAEN         0

//SR bits
#define BSY             7
#define OVR             6
#define MODF            5
#define CRCERR          4
#define WKUP            3
#define TXE             1
#define RXNE            0

#define NSS1           4
#define SCK1           5
#define MOSI1          6
#define MISO1          7

#define NSS2           5
#define SCK2           6
#define MOSI2          3
#define MISO2          2



void SPI_SlaveInit(void);
void SPI_MasterInit(void);
void SPI_Transmit(char data);

#endif