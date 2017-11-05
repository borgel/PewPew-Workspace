#include "dac.h"
#include "project.h"

#include <stdint.h>

#define CONTROL_BITA        (0x5)   //0b0101 write to buffer
#define CONTROL_BITB        (0xC)   //0b1100 write to reg a, buffer to b

void dac_Init(void){
    SPI_DAC_Start();
    
    UART_DEBUG_PutString("Done initting DAC\n");
}

void dac_WriteSamples(uint16_t x, uint16_t y) {
    uint16_t v;
    // mask to 12 bits
    v = (y & 0xFFF) | (CONTROL_BITA << 12);
    SPI_DAC_Write(v);
    
    v = (x & 0xFFF) | (CONTROL_BITB << 12);
    SPI_DAC_Write(v);
}
