#define _CRT_SECURE_NO_WARNINGS 1

//��λ��������ϰ��

/*
��ҵ����(705)
ͳ�ƶ�������1�ĸ���

��ҵ����
дһ���������ز����������� 1 �ĸ�����

���磺 15    0000 1111    4 �� 1
*/

//�ⷨһ������ + ��λ��
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

//�ⷨ������λ��
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
��ҵ����(706)
��ӡ���������Ƶ�����λ��ż��λ

��ҵ����
��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
*/
#include <stdio.h>
int main(void)
{
    int n = 15;
    int m = n;
    int h = n;
    printf("����λ��");//��1λ����31λ
    for (int i = 31; i >= 1; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    printf("\n");
    printf("ż��λ��");//��0λ����30λ
    for (int i = 30; i >= 0; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    return 0;
}

/*
��ҵ����(707)
���������������в�ͬλ�ĸ���

��ҵ����
���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��

��������:

1999 2299

�������:7
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