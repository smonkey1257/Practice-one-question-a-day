#define _CRT_SECURE_NO_WARNINGS 1

/*
实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定

如：输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。
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
实现一个函数来交换两个整数的内容。
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
实现函数判断year是不是润年。
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
实现一个函数，判断一个数是不是素数。

利用上面实现的函数打印100到200之间的素数。
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