#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
1. ����֮��

��Ŀ���ӣ�
https://leetcode.cn/problems/two-sum/

����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�

����԰�����˳�򷵻ش𰸡�

ʾ�� 1��

���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��
ʾ�� 2��

���룺nums = [3,2,4], target = 6
�����[1,2]
ʾ�� 3��

���룺nums = [3,3], target = 6
�����[0,1]

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //����ö��
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        int j = 0;
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                //��������ʱ������һ���ռ�Ž��
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    //û��һ��������㷵��NULL
    *returnSize = 0;
    return NULL;

}

