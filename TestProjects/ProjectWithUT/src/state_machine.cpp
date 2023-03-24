#include "state_machine.h"

void state_machine_intialize(StateMachine *state_machine, Modes mode)
{
    state_machine->mode = mode;
    state_machine->present_state = S0;
}

void state_machine_execution(StateMachine *state_machine)
{
    StateMachineStates next_state;

    switch (state_machine->present_state)
    {
    case S0:
        next_state = S1;
        break;
    case S1:
        next_state = S2;
        break;
    case S2:
        next_state = S4;
        break;
    case S3:
        next_state = state_machine->mode == MODE_0 ? S5 : S2;
        break;
    case S4:
        next_state = S3;
        break;
    case S5:
        next_state = state_machine->mode == MODE_0 ? S0 : S4;
        break;
    default:
        next_state = S0;
        break;
    }

    state_machine->present_state = next_state;
}
