#include "threads.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

int* arr = nullptr;
int arr_size = 0;

int min_val = 0;
int max_val = 0;
double avg_val = 0.0;

HANDLE create_thread(LPTHREAD_START_ROUTINE func)
{
    HANDLE hThread = CreateThread(nullptr, 0, func, nullptr, 0, nullptr);

    if (!hThread)
    {
        throw std::runtime_error(
            "CreateThread failed: " + get_last_error_message()
        );
    }

    return hThread;
}

void wait_threads(HANDLE t1, HANDLE t2)
{
    if (WaitForSingleObject(t1, INFINITE) == WAIT_FAILED)
        throw std::runtime_error("WaitForSingleObject failed: " + get_last_error_message());

    if (WaitForSingleObject(t2, INFINITE) == WAIT_FAILED)
        throw std::runtime_error("WaitForSingleObject failed: " + get_last_error_message());
}

void close_threads(HANDLE t1, HANDLE t2)
{
    if (t1 && !CloseHandle(t1))
        std::cerr << "CloseHandle failed: " << get_last_error_message() << std::endl;

    if (t2 && !CloseHandle(t2))
        std::cerr << "CloseHandle failed: " << get_last_error_message() << std::endl;
}

DWORD WINAPI min_max(LPVOID param)
{
    if (arr_size == 0) return 0;

    min_val = arr[0];
    max_val = arr[0];

    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
        Sleep(7);
    }

    std::cout << "Min element: " << min_val << std::endl;
    std::cout << "Max element: " << max_val << std::endl;

    return 0;
}

DWORD WINAPI average(LPVOID param)
{
    if (arr_size == 0) return 0;

    int sum = 0;
    for (int i = 0; i < arr_size; i++)
    {
        sum += arr[i];
        Sleep(12);
    }

    avg_val = static_cast<double>(sum) / arr_size;

    std::cout << "Average: " << (int)std::round(avg_val) << std::endl;

    return 0;
}


std::string get_last_error_message()
{
    DWORD error = GetLastError();
    LPSTR buffer = nullptr;

    FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |  // Windows сама выделяет память для строки
        FORMAT_MESSAGE_FROM_SYSTEM |      // текст берётся из системных сообщений
        FORMAT_MESSAGE_IGNORE_INSERTS,    // игнорируем %1, %2 в тексте

        nullptr,                          // источник сообщений (NULL = системный)
        error,                            // код ошибки (GetLastError)
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // язык сообщения
        (LPSTR)&buffer,                   // адрес указателя на строку
        0,                                // размер буфера (не нужен, память выделена автоматически)
        nullptr                           // аргументы для вставок (%1, %2)
    );

    std::string message = buffer ? buffer : "Unknown error";

    LocalFree(buffer); //освобождение буфера

    return message;
}