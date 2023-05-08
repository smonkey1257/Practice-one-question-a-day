#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//���������ڿӷ���(���ؿӵ����꣬Ϊ�˿��Խ����������������)
int PartSort(int* a, int left, int right)
{
	//����ȡ���Ż�

	int begin = left;
	int end = right;
	int pivot = begin;
	int key = a[begin];

	while (begin < end)
	{
		//��������С
		while (begin < end && a[end] >= key)
			--end;

		//�ҵ�����������
		a[pivot] = a[end];
		pivot = end;

		//�����ң��Ҵ�
		while (begin < end && a[begin] <= key)
			++begin;

		//�ҵ������ұ߷�
		a[pivot] = a[begin];
		pivot = begin;
	}
	//ѭ�����������key��λ��
	a[pivot] = key;

	return pivot;
}

void QuickSort(int* a, int left, int right)
{
	//�ݹ����������left>right,�����䲻���ڣ�left=right,ֻ��һ������
	if (left >= right)
		return;

	int KeyIndex = PartSort(a, left, right);

	//[left, KeyIndex - 1] KeyIndex [KeyIndex + 1, rgiht]
	//����������������������������

	//С�����Ż�

	QuickSort(a, left, KeyIndex - 1);
	QuickSort(a, KeyIndex + 1, right);

}


int runeReserve(int* runes, int runesSize) {
	//�Է���ħ��ֵ����
	QuickSort(runes, 0, runesSize - 1);

	//�����Ƚ����������
	int MaxRunes = 1;//��¼���ֵ
	int TheMax = 1;//��¼��ǰ���ֵ
	for (int i = 0; i < runesSize - 1; i++)
	{
		//6������ֻ��Ƚ�5�Σ���˳�ʼֵӦ��Ϊ1
		TheMax++;
		if (abs(runes[i] - runes[i + 1]) > 1)
		{
			TheMax = 1;
		}
		if (TheMax > MaxRunes)
		{
			MaxRunes = TheMax;
		}

	}
	return MaxRunes;
}