#include <gtest/gtest.h>
#include <source.h>

TEST(SourceTest, assert_true)
{
    ASSERT_TRUE(source_func() == 0);
}

TEST(SourceTest, Assert_false)
{
    ASSERT_FALSE(source_func() != 0);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}