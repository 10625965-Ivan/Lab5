#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tasks.h"

#define MAX_N 100

static void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static int read_int(const char* text, int* value, int min, int max)
{
    printf("%s", text);
    if (scanf("%d", value) != 1 || *value < min || *value > max) {
        printf("Некоректне введення\n");
        clear_input();
        return 0;
    }
    return 1;
}

static int read_double(const char* text, double* value)
{
    printf("%s", text);
    if (scanf("%lf", value) != 1) {
        printf("Некоректне введення\n");
        clear_input();
        return 0;
    }
    return 1;
}

static void print_real_array(const double* arr, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%.4f ", arr[i]);
    printf("\n");
}

static double random_real(double a, double b)
{
    return a + (b - a) * rand() / ((double)RAND_MAX + 1.0);
}

void task3(void)
{
    double arr[15];
    int ints[15];

    printf("а) дійсні значення від 0 до 1:\n");
    for (int i = 0; i < 15; ++i)
        arr[i] = (double)rand() / RAND_MAX;
    print_real_array(arr, 15);

    printf("б) дійсні значення x (22 <= x < 23):\n");
    for (int i = 0; i < 15; ++i)
        arr[i] = random_real(22.0, 23.0);
    print_real_array(arr, 15);

    printf("в) дійсні значення x (0 <= x < 10):\n");
    for (int i = 0; i < 15; ++i)
        arr[i] = random_real(0.0, 10.0);
    print_real_array(arr, 15);

    printf("г) дійсні значення x (-50 <= x < 50):\n");
    for (int i = 0; i < 15; ++i)
        arr[i] = random_real(-50.0, 50.0);
    print_real_array(arr, 15);

    printf("д) цілі значення від 0 до 10 включно:\n");
    for (int i = 0; i < 15; ++i) {
        ints[i] = rand() % 11;
        printf("%d ", ints[i]);
    }
    printf("\n");
}

void task10(void)
{
    int n;
    int digits[6];
    int count = 0;

    if (!read_int("Введіть натуральне число n (n <= 999999): ", &n, 1, 999999))
        return;

    while (n > 0) {
        digits[count++] = n % 10;
        n /= 10;
    }

    printf("Цифри числа у зворотному порядку:\n");
    for (int i = 0; i < count; ++i)
        printf("%d ", digits[i]);
    printf("\n");
}

void task29(void)
{
    int n;
    double a[MAX_N];

    if (!read_int("Введіть кількість елементів n (1..100): ", &n, 1, MAX_N))
        return;

    for (int i = 0; i < n; ++i) {
        printf("a[%d] = ", i + 1);
        if (!read_double("", &a[i]))
            return;
    }

    int increasing = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1]) {
            increasing = 0;
            break;
        }
    }

    if (increasing)
        printf("Послідовність зростає\n");
    else
        printf("Послідовність не зростає\n");
}

void task66(void)
{
    int n;
    int a[MAX_N];

    if (!read_int("Введіть кількість елементів n (1..100): ", &n, 1, MAX_N))
        return;

    for (int i = 0; i < n; ++i) {
        printf("a[%d] = ", i + 1);
        if (scanf("%d", &a[i]) != 1) {
            printf("Некоректне введення\n");
            clear_input();
            return;
        }
    }

    long long product = 1;
    int found = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            product *= a[i];
            found = 1;
        }
    }

    if (found)
        printf("Добуток від'ємних елементів: %lld\n", product);
    else
        printf("Від'ємних елементів немає\n");
}

void task127(void)
{
    int n;
    double a[MAX_N];

    if (!read_int("Введіть кількість елементів n (1..100): ", &n, 1, MAX_N))
        return;

    double p1 = 1.0;
    double p2 = 1.0;
    int negatives = 0;
    int positives = 0;

    for (int i = 0; i < n; ++i) {
        printf("a[%d] = ", i + 1);
        if (!read_double("", &a[i]))
            return;
        if (a[i] == 0.0) {
            printf("У послідовності можуть бути лише додатні та від'ємні числа\n");
            return;
        }
        if (a[i] < 0.0) {
            p1 *= a[i];
            ++negatives;
        }
        else {
            p2 *= a[i];
            ++positives;
        }
    }

    if (negatives == 0 || positives == 0) {
        printf("Порівняння неможливе: у послідовності немає елементів обох знаків\n");
        return;
    }

    printf("Добуток від'ємних елементів P1 = %.10g\n", p1);
    printf("Добуток додатних елементів P2 = %.10g\n", p2);

    if (fabs(p2) > fabs(p1))
        printf("За модулем більший добуток додатних елементів\n");
    else if (fabs(p2) < fabs(p1))
        printf("За модулем більший добуток від'ємних елементів\n");
    else
        printf("Добутки рівні за модулем\n");
}

void task8(void)
{
    double ap[10];
    double gp[20];
    long long fib[12];
    double first;
    double diff;
    double a;
    double z;

    if (!read_double("Введіть перший член арифметичної прогресії i: ", &first))
        return;
    if (!read_double("Введіть різницю p: ", &diff))
        return;
    if (!read_double("Введіть перший член геометричної прогресії a: ", &a))
        return;
    if (!read_double("Введіть знаменник z: ", &z))
        return;

    ap[0] = first;
    for (int k = 1; k < 10; ++k)
        ap[k] = ap[k - 1] + diff;

    gp[0] = a;
    for (int k = 1; k < 20; ++k)
        gp[k] = gp[k - 1] * z;

    fib[0] = 1;
    fib[1] = 1;
    for (int k = 2; k < 12; ++k)
        fib[k] = fib[k - 1] + fib[k - 2];

    printf("а) перші десять членів арифметичної прогресії:\n");
    for (int k = 0; k < 10; ++k)
        printf("%g ", ap[k]);
    printf("\n");

    printf("б) перші двадцять членів геометричної прогресії:\n");
    for (int k = 0; k < 20; ++k)
        printf("%g ", gp[k]);
    printf("\n");

    printf("в) перші дванадцять членів послідовності Фібоначчі:\n");
    for (int k = 0; k < 12; ++k)
        printf("%lld ", fib[k]);
    printf("\n");
}
