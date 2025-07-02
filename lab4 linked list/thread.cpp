#include <stdio.h>
#include <windows.h>

#define MAX 10

DWORD WINAPI print_even(LPVOID arg) {
    for (int i = 0; i <= MAX; i += 2) {
        printf("Even: %d\n", i);
    }
    return 0;
}

DWORD WINAPI print_odd(LPVOID arg) {
    for (int i = 1; i <= MAX; i += 2) {
        printf("Odd: %d\n", i);
    }
    return 0;
}

int main() {
    HANDLE thread1, thread2;

    thread1 = CreateThread(NULL, 0, print_even, NULL, 0, NULL);  // First thread for even numbers
    thread2 = CreateThread(NULL, 0, print_odd, NULL, 0, NULL);   // Second thread for odd numbers

    WaitForSingleObject(thread1, INFINITE);  // Wait for first thread
    WaitForSingleObject(thread2, INFINITE);  // Wait for second thread

    CloseHandle(thread1);
    CloseHandle(thread2);

    printf("Main Thread Finished\n");

    return 0;
}
