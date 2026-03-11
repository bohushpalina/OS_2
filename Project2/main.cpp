#include "threads.h"
#include "input.h"
#include "array_utils.h"
#include <windows.h>
#include <iostream>

int main()
{
    HANDLE hMinMax = nullptr;
    HANDLE hAverage = nullptr;

    try
    {
        read_array();

        hMinMax = create_thread(min_max);
        hAverage = create_thread(average);

        wait_threads(hMinMax, hAverage);

        replace_min_max();

        print_array();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    close_threads(hAverage, hMinMax);
    delete_array();

    return 0;
}
