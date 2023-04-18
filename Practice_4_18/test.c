#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
/*
* ��a = 7, b = 1 + 3 * 6 = 19 ---------- ���� a <= 100, b <= 20
*   a = 8, b = 1 + 3 * 7 = 22 ---------������ b <= 20 ,����ѭ��
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


// ��������Ļ����� 9 * 9 �˷��ھ���
/*
	1. printf("\n");
	2. ��1��ʼ��9����
	3. �����ո�
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
* ������ʮ�����������ֵ
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
	printf("���ֵ max = %d\n", max);
	return 0;
}

/*
* �ġ��������
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
* �塢��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
*/
int main(void)
{
	int count = 0;
	for (int i = 1; i <= 100; i++)
	{
		//��λ��9
		if (i % 10 == 9)
			count++;
		//ʮλ��9
		else if (i / 10 == 9)
			count++;
		//99������
		else if (i == 99)
		{
			count += 2;
			break;
		}
	}
	printf("����9�ĸ���Ϊ%d\n", count);
	return 0;
}


/*
* ������д������һ���������������в��Ҿ����ĳ����
* 
* Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����
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
			printf("�ҵ����±�Ϊ��%d\n", mid);
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
		printf("û�ҵ�");

	return 0;
}