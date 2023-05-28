#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define N 51
int main(void)
{
    int n = 0;
    scanf("%d", &n);

    //统计工龄（顺便还能排好序）
    int arr[N] = { 0 };
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        ++arr[tmp];
    }

    //打印输出(所有工龄的可能值)
    for (int i = 0; i < N; i++)
    {
        if (arr[i])
        {
            printf("%d:%d\n", i, arr[i]);
        }
    }
    return 0;
}