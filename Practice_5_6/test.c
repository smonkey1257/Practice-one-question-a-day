#define _CRT_SECURE_NO_WARNINGS 1


//��ҵ����(696)
//��������
//
//��ҵ����
//������A�е����ݺ�����B�е����ݽ��н�����������һ����

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
//	printf("����ǰ��\n");
//	arrPrint(arr1, sz);
//	putchar('\n');
//	arrPrint(arr2, sz);
//	putchar('\n');
//
//	arrSwap(arr1, arr2, sz);
//
//	printf("������\n");
//	arrPrint(arr1, sz);
//	putchar('\n');
//	arrPrint(arr2, sz);
//	putchar('\n');
//
//	return 0;
//}


/*
��ҵ����(697)
�������

��ҵ����
����һ���������飬��ɶ�����Ĳ���

1.ʵ�ֺ���init() ��ʼ������Ϊȫ0
2.ʵ��print()  ��ӡ�����ÿ��Ԫ��
3.ʵ��reverse()  �����������Ԫ�ص����á�

Ҫ���Լ�������Ϻ����Ĳ���������ֵ��

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

	//��β����
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
//	//��ʼ������
//	arrInit(arr, sz);
//	arrPrint(arr, sz);
//	putchar('\n');
//
//	arrInput(arr, sz);
//	arrPrint(arr, sz);
//	putchar('\n');
//
//	//����Ԫ������
//	arrReverse(arr, sz);
//	arrPrint(arr, sz);
//
//	return 0;
//}


/*
��ҵ����(698)
ð������

��ҵ����
ʵ��һ�������������ð������
*/

//ð��������

//��д������ʹ�����Ѿ������˵��������ڱȽϣ�Ч��̫��
void bubbleSort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)//����
	{
		//һ�˿�ʼ�����Ѿ�����
		int flag = 1;
		for (int j = 0; j < sz - 1 - i; j++)//�ȽϽ�������
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
