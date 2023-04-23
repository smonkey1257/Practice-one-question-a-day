#define _CRT_SECURE_NO_WARNINGS 1

/*
ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��

�磺����9�����9*9�ھ������12�����12*12�ĳ˷��ھ���
*/
#include <stdio.h>

void MultiplicationTable(num)
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%2d*%2d=%3d ", j, i, j * i);
		}
		printf("\n");
	}
}
int main(void)
{
	int num = 0;
	scanf("%d", &num);

	MultiplicationTable(num);

	return 0;
}

/*
ʵ��һ�������������������������ݡ�
*/
#include <stdio.h>
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(void)
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}

/*
ʵ�ֺ����ж�year�ǲ������ꡣ
*/
#include <stdio.h>
int isLeapYear1(year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;
	else
		return 0;
}
int isLeapYear2(year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

}
int main(void)
{
	int year = 0;
	scanf("%d", &year);

	if (isLeapYear1(year))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}


/*
ʵ��һ���������ж�һ�����ǲ���������

��������ʵ�ֵĺ�����ӡ100��200֮���������
*/
#include <stdio.h>
#include <math.h>
int IsPrimeNumber(n)
{
	for (int i = 3; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main(void)
{
	int count = 0;
	for (int i = 101; i <= 200; i+=2)
	{
		if (IsPrimeNumber(i))
		{
			printf("%d ", i);
			count++;
		}
		if (count == 7)
		{
			count = 0;
			putchar('\n');
		}
	}
	return 0;
}