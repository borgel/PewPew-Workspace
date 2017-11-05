#include "laser.h"
#include "project.h"

#include "dac.h"

#include <stdint.h>

void laser_Init(void) {
    dac_Init();
}

void laser_SetGate(laser_GateState laserEnable) {
    //LaserGatePin_Write(laserEnable == LASER_GATE_ENABLE_LASER);
    Cy_GPIO_Write(LaserGatePin_PORT, LaserGatePin_NUM, laserEnable == LASER_GATE_ENABLE_LASER);
}

void laser_SetXY(uint16_t x, uint16_t y) {
    dac_WriteSamples(x, y);
}

void dac_DoCSVArray(laser_CommandStruct * cmds, int len) {
    for(int step = 0; step < len; step++) {
        laser_SetGate(cmds[step].gate);
        laser_SetXY(cmds[step].x, cmds[step].y);
        
        CyDelayUs(50);
    }
}