#include "threads.h"
#include "input.h"
#include <iostream>
#include <stdexcept>

void read_array()
{
    std::cout << "Enter array size: ";

    if (!(std::cin >> arr_size) || arr_size <= 0)
        throw std::runtime_error("Invalid array size");

    arr = new int[arr_size];

    std::cout << "Enter elements:\n";

    for (int i = 0; i < arr_size; i++)
    {
        if (!(std::cin >> arr[i]))
            throw std::runtime_error("Invalid element");
    }
}

void delete_array()
{
    delete[] arr;
}
