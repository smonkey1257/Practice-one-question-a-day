#define _CRT_SECURE_NO_WARNINGS 1


//作业标题(696)
//交换数组
//
//作业内容
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）

#include <stdio.h>

void arrSwap(int arr1[], int arr2[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

void arrPrint(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
//
//int main(void)
//{
//	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int arr2[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr1) / sizeof(int);
//	
//	printf("交换前：\n");
//	arrPrint(arr1, sz);
//	putchar('\n');
//	arrPrint(arr2, sz);
//	putchar('\n');
//
//	arrSwap(arr1, arr2, sz);
//
//	printf("交换后：\n");
//	arrPrint(arr1, sz);
//	putchar('\n');
//	arrPrint(arr2, sz);
//	putchar('\n');
//
//	return 0;
//}


/*
作业标题(697)
数组操作

作业内容
创建一个整形数组，完成对数组的操作

1.实现函数init() 初始化数组为全0
2.实现print()  打印数组的每个元素
3.实现reverse()  函数完成数组元素的逆置。

要求：自己设计以上函数的参数，返回值。

*/

#include <stdlib.h>
#include <time.h>

void arrInit(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}


void arrReverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;

	//首尾交换
	while (left <= right)
	{
		int tmp = arr[right];
		arr[right] = arr[left];
		arr[left] = tmp;
		
		left++;
		right--;
	}
}

void arrInput(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		arr[i] = (rand() % 20);
	}
}
//
//int main(void)
//{
//	int arr[20];
//	int sz = sizeof(arr) / sizeof(int);
//	
//	srand((unsigned int)time(NULL));
//
//
//	//初始化数组
//	arrInit(arr, sz);
//	arrPrint(arr, sz);
//	putchar('\n');
//
//	arrInput(arr, sz);
//	arrPrint(arr, sz);
//	putchar('\n');
//
//	//数组元素逆置
//	arrReverse(arr, sz);
//	arrPrint(arr, sz);
//
//	return 0;
//}


/*
作业标题(698)
冒泡排序

作业内容
实现一个对整形数组的冒泡排序
*/

//冒泡排升序

//该写法，即使数据已经有序了但数据仍在比较，效率太低
void bubbleSort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)//趟数
	{
		//一趟开始假设已经有序
		int flag = 1;
		for (int j = 0; j < sz - 1 - i; j++)//比较交换次数
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}

		if (flag == 1)
			break;
	}
}

int main(void)
{
	int arr[10];
	int sz = sizeof(arr) / sizeof(int);

	arrInput(arr, sz);
	arrPrint(arr, sz);
	putchar('\n');

	bubbleSort(arr, sz);
	arrPrint(arr, sz);
	putchar('\n');

	return 0;
}
