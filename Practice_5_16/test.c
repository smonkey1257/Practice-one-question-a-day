#define _CRT_SECURE_NO_WARNINGS 1

//按位操作符练习题

/*
作业标题(705)
统计二进制中1的个数

作业内容
写一个函数返回参数二进制中 1 的个数。

比如： 15    0000 1111    4 个 1
*/

//解法一：右移 + 按位与
int NumberOf1(int n) {
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (n & 1)
            count++;

        n >>= 1;
    }
    return count;
}

//解法二：按位与
int NumberOf1(int n) {
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}
/*
作业标题(706)
打印整数二进制的奇数位和偶数位

作业内容
获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
*/
#include <stdio.h>
int main(void)
{
    int n = 15;
    int m = n;
    int h = n;
    printf("奇数位：");//第1位到第31位
    for (int i = 31; i >= 1; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    printf("\n");
    printf("偶数位：");//第0位到第30位
    for (int i = 30; i >= 0; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    return 0;
}

/*
作业标题(707)
求两个数二进制中不同位的个数

作业内容
编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？

输入例子:

1999 2299

输出例子:7
*/

#include <stdio.h>

int main() {
    int m = -1;
    int n = 0;
    scanf("%d %d", &m, &n);
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((m & 1) != (n & 1))
            count++;

        m >>= 1;
        n >>= 1;
    }
    printf("%d", count);
    return 0;
}