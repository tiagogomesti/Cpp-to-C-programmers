#include <gtest/gtest.h>
#include <swap.h>

template <class T>
void test_swap(const T &d1_input, const T &d2_input)
{
    T d1 = d1_input;
    T d2 = d2_input;

    swap(d1, d2);

    ASSERT_DOUBLE_EQ(d1, d2_input);
    ASSERT_DOUBLE_EQ(d2, d1_input);
}

TEST(TestSwap, SwapDoubles)
{
    double d1 = 10.0;
    double d2 = 20.0;
    test_swap(d1, d2);
}

TEST(TestSwap, SwapFloat)
{
    float d1 = 10.0;
    float d2 = 20.0;
    test_swap(d1, d2);
}

TEST(TestSwap, SwapInt)
{
    int d1 = 10;
    int d2 = 20;
    test_swap(d1, d2);
}

TEST(TestSwap, SwapChar)
{
    char d1 = 'a';
    char d2 = 'b';
    test_swap(d1, d2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}