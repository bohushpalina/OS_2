#ifndef THREADS_H
#define THREADS_H

#include <windows.h>
#include <string>

extern int* arr;
extern int arr_size;

extern int min_val;
extern int max_val;
extern double avg_val;

HANDLE create_thread(LPTHREAD_START_ROUTINE func);
void wait_threads(HANDLE t1, HANDLE t2);
void close_threads(HANDLE t1, HANDLE t2);

DWORD WINAPI min_max(LPVOID param);
DWORD WINAPI average(LPVOID param);

std::string get_last_error_message();

#endif
