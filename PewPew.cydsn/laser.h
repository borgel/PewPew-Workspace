#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t gate;
    uint16_t x;
    uint16_t y;
} laser_CommandStruct;

typedef enum {
    LASER_GATE_ENABLE_LASER,
    LASER_GATE_DISABLE_LASER,
} laser_GateState;

void laser_Init(void);

void laser_SetGate(laser_GateState laserEnable);
void laser_SetXY(uint16_t x, uint16_t y);

void dac_DoCSVArray(laser_CommandStruct * cmds, int len);