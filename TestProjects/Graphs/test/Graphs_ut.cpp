#include <Graphs.h>
#include <gtest/gtest.h>

#include <iostream>

static inline void print_all_vector(vector<int> &d)
{
    for (uint32_t i = 0; i < d.size(); i++)
    {
        cout << d[i] << ", ";
    }
    cout << endl;
}

TEST(GraphsTest, test_vectors)
{
    cout << "#################################\n\n";

    vector<int> d;

    for (uint32_t i = 0; i < 10; i++)
    {
        d.insert(d.end(), i);
    }

    print_all_vector(d);
    d.erase(d.begin() + 3);
    print_all_vector(d);

    cout << "\n\n#################################\n\n";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
