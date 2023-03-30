#include <gtest/gtest.h>
#include <week_1_assessment.h>

TEST(week_1_testTest, main)
{
    vector<int> data;
    int local_sum = 0;

    for (int i = 0; i < N; i++)
    {
        local_sum += i;
        data.insert(data.end(), i);
    }

    int accum = 0;
    sum(accum, N, data);

    ASSERT_EQ(accum, local_sum);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}