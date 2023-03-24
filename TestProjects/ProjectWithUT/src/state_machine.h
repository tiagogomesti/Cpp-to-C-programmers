#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <cstdint>

typedef enum
{
    S0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S_MAX
} StateMachineStates;

typedef enum
{
    MODE_0,
    MODE_1
} Modes;

typedef struct 
{
    StateMachineStates present_state;
    Modes mode;
} StateMachine;

void state_machine_intialize(StateMachine *state_machine, Modes mode);
void state_machine_execution(StateMachine *state_machine);

#endif