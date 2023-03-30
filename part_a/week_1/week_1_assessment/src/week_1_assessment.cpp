#include "week_1_assessment.h"

void sum(int &p, int n, vector<int> d)
{
    p = 0;

    for (int i = 0; i < n; i++)
    {
        p += d[i];
    }
}
