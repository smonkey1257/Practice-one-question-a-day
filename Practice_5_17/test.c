#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/* 打印菱形 */

//经过总结，无非就是先打印前置空格，然后再打印*，
//然后就是正三角行和倒三角形
//倒三角形其实就是第一个循环的前6次循环的逆序执行﻿﻿
int main() {
    int n = 7;
    //正三角
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j < 2 * i; j++)
        {
            printf("*");
        }
        //printf("a");
        printf("\n");
    }
    //倒三角
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j < 2 * i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}


#include <stdio.h>
#include <math.h>


int main(void)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i <= 100000; i++)
    {
        sum = 0;
        int tmp = i;
        count = 0;
        while (tmp)//一个数有几位
        {
            tmp /= 10;
            count++;
        }
        tmp = i;
        while (tmp)//每位乘方求和
        {
            sum += (int)pow(tmp % 10, count);
            tmp /= 10;
        }
        if (sum == i)//判断水仙花数
        {
            printf("%d\n", i);
        }
    }
    return 0;
}


/*
求出0～100000之间的所有“水仙花数”并输出。

“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。
*/
#include <math.h>
int main(void)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i <= 100000; i++)
    {
        sum = 0;
        int tmp = i;
        count = 0;
        while (tmp)//一个数有几位
        {
            tmp /= 10;
            count++;
        }
        tmp = i;
        while (tmp)//每位乘方求和
        {
            sum += (int)pow(tmp % 10, count);
            tmp /= 10;
        }
        if (sum == i)//判断水仙花数
        {
            printf("%d\n", i);
        }
    }
    return 0;
}