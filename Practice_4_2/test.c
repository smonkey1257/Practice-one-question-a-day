#define _CRT_SECURE_NO_WARNINGS 1
/*
����һ������ nums �����顸��̬�͡��ļ��㹫ʽΪ��runningSum[i] = sum(nums[0]��nums[i]) ��

�뷵�� nums �Ķ�̬�͡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/running-sum-of-1d-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//��һ�ַ�����
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* runningSum = (int*)malloc(numsSize * sizeof(int));
    int sum = 0;
    int i = 0;
    //��������˵������׳˺ͻ��Ǻ����
    for (i = 0; i < numsSize; i++)
    {
        //���㵱ǰ�ĺ�
        sum += nums[i];
        //�ѵ�ǰ�͸�������
        runningSum[i] = sum;
    }
    return runningSum;
}
//�ռ临�Ӷ��Ը�

//�ڶ��ַ���������쳲����������������
int* runningSum(int* nums, int numsSize, int* returnSize) {
    
    //��һ����Ϊ�˸�����վ���ص������Ԫ�ظ���
    *returnSize = numsSize;
    
    int i = 0;
    //ԭ���޸�����
    for (i = 1; i < numsSize; i++)
    {
        //
        nums[i] += nums[i - 1];
    }
    return nums;
}