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

/* ��Ĵ��뽫��Ƕ������ */

double dist(double h, double p)
{
    double sum = h;
    while (h * p >= TOL)
    {
        //������һ���µĸ߶Ⱥ󣬸߶ȵ�p��Ҫ����TOL
        h *= p;
        sum += (2 * h);
    }
    return sum;
}