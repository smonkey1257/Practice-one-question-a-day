#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//单趟排序（挖坑法）(返回坑的坐标，为了可以进行左右区间的排序)
int PartSort(int* a, int left, int right)
{
	//三数取中优化

	int begin = left;
	int end = right;
	int pivot = begin;
	int key = a[begin];

	while (begin < end)
	{
		//坑在左，找小
		while (begin < end && a[end] >= key)
			--end;

		//找到后把它往左放
		a[pivot] = a[end];
		pivot = end;

		//坑在右，找大
		while (begin < end && a[begin] <= key)
			++begin;

		//找到后往右边放
		a[pivot] = a[begin];
		pivot = begin;
	}
	//循环结束后就是key的位置
	a[pivot] = key;

	return pivot;
}

void QuickSort(int* a, int left, int right)
{
	//递归结束条件：left>right,子区间不存在；left=right,只有一个数据
	if (left >= right)
		return;

	int KeyIndex = PartSort(a, left, right);

	//[left, KeyIndex - 1] KeyIndex [KeyIndex + 1, rgiht]
	//单趟排序完进行左右子区间的排序

	//小区间优化

	QuickSort(a, left, KeyIndex - 1);
	QuickSort(a, KeyIndex + 1, right);

}


int runeReserve(int* runes, int runesSize) {
	//对符文魔力值排序
	QuickSort(runes, 0, runesSize - 1);

	//遍历比较找最大数量
	int MaxRunes = 1;//记录最大值
	int TheMax = 1;//记录当前最大值
	for (int i = 0; i < runesSize - 1; i++)
	{
		//6个数据只会比较5次，因此初始值应该为1
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