#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define N 51
int main(void)
{
    int n = 0;
    scanf("%d", &n);

    //ͳ�ƹ��䣨˳�㻹���ź���
    int arr[N] = { 0 };
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        ++arr[tmp];
    }

    //��ӡ���(���й���Ŀ���ֵ)
    for (int i = 0; i < N; i++)
    {
        if (arr[i])
        {
            printf("%d:%d\n", i, arr[i]);
        }
    }
    return 0;
}