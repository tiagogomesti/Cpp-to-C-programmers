#include <gtest/gtest.h>
#include <state_machine.h>

TEST(StateMachine, InitialState)
{
    StateMachine state_machine;

    state_machine_intialize(&state_machine, MODE_0);
    ASSERT_EQ(state_machine.present_state, S0);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}