#ifndef SUMMING_ARRAY_TEMPLATE_TEMPLATE_H
#define SUMMING_ARRAY_TEMPLATE_TEMPLATE_H

#include <stddef.h>

template <class T>
T summing_array_template(T *array, size_t array_size)
{
    T sum = 0;

    for (size_t i = 0; i < array_size; i++)
    {
        sum += array[i];
    }

    return sum;
}

#endif