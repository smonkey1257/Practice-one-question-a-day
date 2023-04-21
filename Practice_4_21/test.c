#define _CRT_SECURE_NO_WARNINGS 1

/*
第一题：小乐乐求和（https://www.nowcoder.com/practice/ce0b2eacd3d04647831358c2876e44ff?tpId=107&&tqId=33393&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking）

描述
小乐乐最近接触了求和符号Σ，他想计算的结果。但是小乐乐很笨，请你帮助他解答。

输入描述：
输入一个正整数n  (1 ≤ n ≤ 109)

输出描述：
输出一个值，为求和结果。

示例1
输入：1
输出：1
*/

#include <stdio.h>

int main()
{
    //(1 ≤ n ≤ 109) - 求和应该是一个很大的数字
    int n = 0;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    printf("%lld\n", sum);
    return 0;
}

/*
* 第二题：小乐乐找最大数(https://www.nowcoder.com/practice/ae6a21920cac4f9184c8ecfcc87f89b9?tpId=107&&tqId=33404&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking)
* 
* 描述：小乐乐获得4个最大数，请帮他编程找到最大的数。
* 输入描述：
* 一行，4个整数，用空格分开。
* 
* 输出描述：
* 一行，一个整数，为输入的4个整数中最大的整数。
* 
* 示例1
* 输入：5 8 2 5
* 输出：8

*/

#include <stdio.h>

//重复利用一个变量，不用数组
int main()
{
    int num = 0;
    scanf("%d", &num);
    int max = num;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &num);
        if (max < num)
            max = num;
    }
    printf("%d\n", max);
    return 0;
}

/*
第三题：判断是不是字母（https://www.nowcoder.com/practice/91a588dd4cd244bfa616f17603ec123c?tpId=107&&tqId=33328&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking）

描述
KiKi想判断输入的字符是不是字母，请帮他编程实现。

输入描述：
多组输入，每一行输入一个字符。
输出描述：
针对每组输入，输出单独占一行，判断输入字符是否为字母，输出内容详见输出样例。
示例1
输入：
A
6
输出：
A is an alphabet.
6 is not an alphabet.
*/

#include <stdio.h>

int main()
{
    char ch = 0;
    while ((ch = getchar()) != EOF)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            printf("%c is an alphabet.\n", ch);
        }
        else
        {
            printf("%c is not an alphabet.\n", ch);
        }
        //换行干扰
        getchar();
    }
    return 0;
}

/*
第四题：网购（https://www.nowcoder.com/practice/5d7dfd405e5f4e4fbfdff6862c46b751?tpId=107&&tqId=33318&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking）

描述
KiKi非常喜欢网购，在一家店铺他看中了一件衣服，他了解到，
如果今天是“双11”（11月11日）则这件衣服打7折，
“双12” （12月12日）则这件衣服打8折，
如果有优惠券可以额外减50元（优惠券只能在双11或双12使用），求KiKi最终所花的钱数。

数据范围：衣服价格满足 1≤val≤100000

输入描述：
一行，四个数字，第一个数表示小明看中的衣服价格，
第二和第三个整数分别表示当天的月份、当天的日期、
第四个整数表示是否有优惠券（有优惠券用1表示，无优惠券用0表示）。 注：输入日期保证只有“双11”和“双12”。
输出描述：
一行，小明实际花的钱数（保留两位小数）。（提示：不要指望商家倒找你钱）
*/

#include <stdio.h>

int main()
{
    float val = 0.0f;
    int month = 0;
    int day = 0;
    int flag = 0;

    //输入
    scanf("%f %d %d %d", &val, &month, &day, &flag);
    //最终花费
    if (month == 11 && flag == 1)
    {
        val = 0.7 * val - 50;
    }
    else if (month == 11 && flag != 1)
    {
        val = 0.7 * val;
    }
    else if (month == 12 && flag == 1)
    {
        val = 0.8 * val - 50;
    }
    else
    {
        val = 0.8 * val;
    }

    if (val <= 0)
        val = 0.0f;

    printf("%0.2f\n", val);
    return 0;
}