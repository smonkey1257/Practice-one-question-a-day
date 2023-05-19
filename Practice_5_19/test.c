#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

double fn(double x, int n);

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x, n));

    return 0;
}

/* 你的代码将被嵌在这里 */
double fn(double x, int n)
{
    return n == 1 ? x : (pow(-1, n - 1) * pow(x, n) + fn(x, n - 1));
}
