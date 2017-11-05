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

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */

    UART_DEBUG_Start();
    
    UART_DEBUG_PutString("\r\nStarting...\n");
    
    DAC_CLOCK_Enable();

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
