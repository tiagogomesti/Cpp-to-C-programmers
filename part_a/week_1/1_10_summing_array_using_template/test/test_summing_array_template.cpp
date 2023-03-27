#include <gtest/gtest.h>
#include <summing_array_template.h>

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

static const size_t ARRAY_SIZE = 128;
static const uint32_t MAX_VALUE = 100000;

static inline int rand_int_gen(void);
static inline int rand_float_gen(void);
static inline int rand_double_gen(void);
template <class T>
void generate_test_array(T *array, T &sum, T (*rand_gen_fun)(void));
template <class T>
void generate_test(T (*rand_gen_fun)(void));

TEST(SummingArrayTemplate, intArray)
{
    generate_test(rand_int_gen);
}

TEST(SummingArrayTemplate, floatArray)
{
    generate_test(rand_float_gen);
}

TEST(SummingArrayTemplate, doubleArray)
{
    generate_test(rand_double_gen);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

static inline int rand_int_gen(void)
{
    return rand() % MAX_VALUE;
}

static inline int rand_float_gen(void)
{
    float f = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / MAX_VALUE));
    return round(f * 100.0) / 100.0;
}

static inline int rand_double_gen(void)
{
    double d = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / MAX_VALUE));
    return round(d * 100.0) / 100.0;
}

template <class T>
void generate_test_array(T *array, T &sum, T (*rand_gen_fun)(void))
{
    sum = 0;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        T data = rand_gen_fun();
        array[i] = data;
        sum += data;
    }
}

template <class T>
void generate_test(T (*rand_gen_fun)(void))
{
    T array[ARRAY_SIZE];
    T sum_expected;
    generate_test_array(array, sum_expected, rand_gen_fun);
    T sum = summing_array_template(array, ARRAY_SIZE);
    EXPECT_EQ(sum, sum_expected);
}
