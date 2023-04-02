#define _CRT_SECURE_NO_WARNINGS 1
/*
给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/running-sum-of-1d-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//第一种方法：
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* runningSum = (int*)malloc(numsSize * sizeof(int));
    int sum = 0;
    int i = 0;
    //本质上来说，跟求阶乘和还是很像的
    for (i = 0; i < numsSize; i++)
    {
        //计算当前的和
        sum += nums[i];
        //把当前和给新数组
        runningSum[i] = sum;
    }
    return runningSum;
}
//空间复杂度略高

//第二种方法：类似斐波那契数列数列求和
int* runningSum(int* nums, int numsSize, int* returnSize) {
    
    //这一步是为了告诉网站返回的数组的元素个数
    *returnSize = numsSize;
    
    int i = 0;
    //原地修改数组
    for (i = 1; i < numsSize; i++)
    {
        //
        nums[i] += nums[i - 1];
    }
    return nums;
}