#define _CRT_SECURE_NO_WARNINGS 1
/*
* 小乐乐定闹钟
https://www.nowcoder.com/practice/0f7e422e12be4a7f9958ca2a82abc775?tpId=107&&tqId=33394&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
输入描述：
输入现在的时刻以及要睡的时长k（单位：minute），中间用空格分开。

输入格式：hour:minute k(如hour或minute的值为1，输入为1，而不是01)

(0 ≤ hour ≤ 23，0 ≤ minute ≤ 59，1 ≤ k ≤ 109)

输出描述：
对于每组输入，输出闹钟应该设定的时刻，输出格式为标准时刻表示法（即时和分都是由两位表示，位数不够用前导0补齐）。
*/


#include <stdio.h>
//1.忽略分钟的总和为这个
//2.%02d:%02d - 输出不规范
//3.(hour + (time + minute) / 60)%24 - 要在24小时范围内
int main()
{
    int hour = 0, minute = 0;
    int time = 0;
    //输入
    scanf("%d:%d %d", &hour, &minute, &time);
    printf("%02d:%02d\n", (hour + (time + minute) / 60) % 24, (time + minute) % 60);
    return 0;
}

/*
字符转ASCII码值

输入描述：
一行，一个字符。
输出描述：
一行，输出输入字符对应的ASCII码。

https://www.nowcoder.com/practice/93f4d05a02d9468db424ed4316bfc8fd?tpId=107&&tqId=33297&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
*/

#include <stdio.h>

int main()
{
    char ch = getchar();
    printf("%d", ch);
    return 0;
}