#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define N 5

/*
��ҵ����(1105)
�������

��ҵ����
����Ļ�ϴ�ӡ������ǡ�

1

1 1

1 2 1

1 3 3 1

����
*/

int main(void)
{
    int arr[N][N] = { 0 };
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}