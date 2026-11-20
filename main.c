#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include "tasks.h"

int main(void)
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
    setvbuf(stdout, NULL, _IONBF, 0);
    srand((unsigned int)time(NULL));

    printf("Завдання 3\n");
    task3();

    printf("\nЗавдання 10\n");
    task10();

    printf("\nЗавдання 29\n");
    task29();

    printf("\nЗавдання 66\n");
    task66();

    printf("\nЗавдання 127\n");
    task127();

    printf("\nЗавдання 8\n");
    task8();

    return 0;
}
