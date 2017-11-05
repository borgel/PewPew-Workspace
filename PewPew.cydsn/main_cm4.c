#include "project.h"

#include <stdbool.h>

#include "laser.h"

#define LASER_MAX       (0xFFF)     //4096
#define LASER_MIN       (0x000)

void doSawtoothWithSquare(bool swap, float scale)
{
    int saw = 0, square = 0;
    int const step = 10;
    int const duration = 0xFFF / 2; // runs twice
    int const third = duration / 3;
    //balance the min and max across center
    int const leftover = LASER_MAX - (scale * LASER_MAX);
    int const scaledMax = (scale * LASER_MAX) + leftover / 2;
    int const scaledMin = leftover / 2;
    
    while(true) {
        laser_SetGate(LASER_GATE_DISABLE_LASER);
        laser_SetXY(scaledMin, scaledMin);
        // wait for the laser to slew to the start point
        for(saw = 0; saw < duration; saw += step){
            CyDelayUs(50);
        }
        
        laser_SetGate(LASER_GATE_ENABLE_LASER);
        for(saw = 0; saw < duration; saw += step) {
            if(saw < third) {
                square = scaledMin;
            }
            else if(saw > third && saw < (2 * third)) {
                square = scaledMax;
            }
            else if(saw > (2 * third)) {
                square = scaledMin;
            }
            
            //x, y
            if(swap) {
                laser_SetXY(saw, square);
            }
            else {
                laser_SetXY(square, saw);
            }
            
            CyDelayUs(50);
        }
    }
}

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    UART_DEBUG_Start();
    
    UART_DEBUG_PutString("\r\nStarting...\n");
    
    laser_Init();
    
    doSawtoothWithSquare(true, 1.0);

    for(;;) {
    }
}
