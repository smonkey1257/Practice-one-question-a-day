#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
1. 两数之和

题目链接：
https://leetcode.cn/problems/two-sum/

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //暴力枚举
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        int j = 0;
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                //满足条件时，开辟一个空间放结果
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    //没有一个结果满足返回NULL
    *returnSize = 0;
    return NULL;

}

