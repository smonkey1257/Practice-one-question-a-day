#define _CRT_SECURE_NO_WARNINGS 1

/*
题目：
给你一个非负整数 num ，请你返回将它变成 0 所需要的步数。 
如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。

输入：num = 14
输出：6
解释：
步骤 1) 14 是偶数，除以 2 得到 7 。
步骤 2） 7 是奇数，减 1 得到 6 。
步骤 3） 6 是偶数，除以 2 得到 3 。
步骤 4） 3 是奇数，减 1 得到 2 。
步骤 5） 2 是偶数，除以 2 得到 1 。
步骤 6） 1 是奇数，减 1 得到 0 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//解题语言 - C语言

//解法一：
int numberOfSteps(int num) {
    int count = 0;
    //while判断循环次数
    while (num) {//将num对2取余判断是否为偶数
        if (num % 2 == 0) { // 偶数
            num /= 2;
        }
        else { // 奇数
            num -= 1;
        }
        count++;//每循环一次标志位加一
    }
    return count;
}

//解法二：位运算
int numberOfSteps(int num) {
    int i;
    for (i = 0; num; num >>= 1) {
        if (num & 1)//减一再除二，相当于两步
            i += 2;
        else
            ++i;//
    }
    return --i;
}
//14 的二进制为 1110， ++i， i=1
//右移一位变成 111， i+=2， i=3
//右移一位变成 11，  i+=2,  i=5
//右移一位变成 1，   i+=2,  i=7, 但是num=1只需要减一就行，这里多计算了一次，

//因此，返回值就要减一。