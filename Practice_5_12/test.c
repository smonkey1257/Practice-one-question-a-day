#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main(void)
{
    int a = 10;
    int b = 20;

    printf("����ǰ��%d %d\n", a, b);

    a = a - b;
    b = b + a;
    a = b - a;
    printf("������1��%d %d\n", a, b);

    a = a + b;
    b = a - b;
    a = a - b;
    printf("������2��%d %d\n", a, b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("������3��%d %d\n", a, b);
}

