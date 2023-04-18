#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
/*
* 当a = 7, b = 1 + 3 * 6 = 19 ---------- 符合 a <= 100, b <= 20
*   a = 8, b = 1 + 3 * 7 = 22 ---------不符合 b <= 20 ,跳出循环
*/
	int a = 0, b = 0;
	for (a = 1, b = 1; a <= 100; a++)
	{
		if (b >= 20) break;
		if (b % 3 == 1)
		{
			b = b + 3;
			continue;
		}
		b = b - 5;
	}
	printf("%d\n", a);
	return 0;
}


// 二、在屏幕上输出 9 * 9 乘法口诀表
/*
	1. printf("\n");
	2. 从1开始到9结束
	3. 调整空格
*/
int main(void)
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d*%d=%2d  ", j, i, j * i);
		}
		printf("\n");
	}
	return 0;
}


/*
* 三、求十个整数的最大值
*/
int main(void)
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int max = arr[0];

	for (int i = 1; i < 10; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	printf("最大值 max = %d\n", max);
	return 0;
}

/*
* 四、分数求和
*/
int main(void)
{
	double sum = 0.0;
	int flag = 1;
	for (int i = 1; i <= 100; ++i)
	{
		sum = sum + (1.0 / i) * flag;
		flag *= -1;
	}
	printf("%lf", sum);
	return 0;
}

/*
* 五、编写程序数一下 1到 100 的所有整数中出现多少个数字9
*/
int main(void)
{
	int count = 0;
	for (int i = 1; i <= 100; i++)
	{
		//个位是9
		if (i % 10 == 9)
			count++;
		//十位是9
		else if (i / 10 == 9)
			count++;
		//99是特例
		else if (i == 99)
		{
			count += 2;
			break;
		}
	}
	printf("出现9的个数为%d\n", count);
	return 0;
}


/*
* 六、编写代码在一个整形有序数组中查找具体的某个数
* 
* 要求：找到了就打印数字所在的下标，找不到则输出：找不到。
*/
int main(void)
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int target = 6;

	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == target)
		{
			printf("找到了下标为：%d\n", mid);
			break;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if(left > right)
		printf("没找到");

	return 0;
}