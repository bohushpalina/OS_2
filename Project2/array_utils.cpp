#include "threads.h"
#include "array_utils.h"
#include <iostream>
#include <cmath>

void replace_min_max()
{
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == min_val || arr[i] == max_val)
            arr[i] = static_cast<int>(std::round(avg_val));
    }
}

void print_array()
{
    std::cout << "\nModified array:\n";

    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}
