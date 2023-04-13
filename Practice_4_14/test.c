#define _CRT_SECURE_NO_WARNINGS 1

/*
7-1 堆栈操作合法性
分数 37
作者 DS课程组
单位 浙江大学
假设以S和X分别表示入栈和出栈操作。
如果根据一个仅由S和X构成的序列，对一个空堆栈进行操作，相应操作均可行（如没有出现删除时栈空）且最后状态也是栈空，
则称该序列是合法的堆栈操作序列。请编写程序，输入S和X序列，判断该序列是否合法。

输入格式:
输入第一行给出两个正整数N和M，其中N是待测序列的个数，M（≤50）是堆栈的最大容量。
随后N行，每行中给出一个仅由S和X构成的序列。序列保证不为空，且长度不超过100。

输出格式:
对每个序列，在一行中输出YES如果该序列是合法的堆栈操作序列，或NO如果不是。

输入样例：
4 10
SSSXXSXXSX
SSSXXSXXS
SSSSSSSSSSXSSXXXXXXXXXXX
SSSXXSXXX

*/

//删除时栈不为空 且 结果栈为空

#include <stdio.h>
#include <string.h>
#define MAX 100
int main(void)
{
    int N = 0, M = 0, i = 0;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        //每次一组数据
        char arr[MAX] = { 0 };
        scanf("%s", arr);

        int count = 0;

        int len = strlen(arr);
        int j = 0;
        for (j = 0; j < len; j++)
        {
            //遍历字符串
            if (arr[j] == 'S')
                count++;
            else
                count--;
            //遍历过程中如果count超出栈容量
            if (count > M)
            {
                count = 1;
                break;
            }
            //栈为空还进行删除操作
            if (count < 0)
            {
                count = 1;
                break;
            }
        }
        //判断
        if (!count)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
