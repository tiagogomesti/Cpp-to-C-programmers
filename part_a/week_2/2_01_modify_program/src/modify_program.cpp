#include "modify_program.h"

#include <iostream>
using namespace std;

template <class T>
T sum(const T data[], int size)
{
    T var = 0;
    for (int i = 0; i < size; i++)
    {
        var += data[i];
    };

    return var;
}

template <class T>
T sub(const T data[], int size)
{
    T var = 0;
    for (int i = 0; i < size; i++)
    {
        var -= data[i];
    };

    return var;
}

int main(void)
{
    cout << "template for sum()" << endl;
    int a[] = {1, 2, 3};
    double b[] = {2.1, 2.2, 2.3};
    cout << sum(a, 3) << endl;
    cout << sum(b, 3) << endl;

    return 0;
}
