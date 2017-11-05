/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

#include "dac.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    UART_DEBUG_Start();
    
    UART_DEBUG_PutString("\r\nStarting...\n");
    
    dac_Init();
    
    //dac_WriteSamples(0xFFF, 0x000);
    //dac_WriteSamples(0x000, 0xFFF);
    //dac_WriteSamples(0xFFF, 0xFFF);

    for(;;)
    {
        for(int i = 0; i < 0xFFF; i+=10) {
            //x, y
            //dac_WriteSamples(0x000, 0xFFF);
            //dac_WriteSamples(0xFFF, 0x000);
            dac_WriteSamples(0xFFF - i, i);
            //UART_DEBUG_PutString(".");
            
            //1ms
            CyDelayUs(50);
        }
    }
}

/* [] END OF FILE */
