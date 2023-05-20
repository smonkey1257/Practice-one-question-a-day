#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define TOL 1E-3

double dist(double h, double p);

int main()
{
    double h, p, d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);
    return 0;
}

/* 你的代码将被嵌在这里 */

double dist(double h, double p)
{
    double sum = h;
    while (h * p >= TOL)
    {
        //产生了一个新的高度后，高度的p倍要大于TOL
        h *= p;
        sum += (2 * h);
    }
    return sum;
}