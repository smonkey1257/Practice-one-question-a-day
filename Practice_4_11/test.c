#define _CRT_SECURE_NO_WARNINGS 1
/*
* С���ֶ�����
https://www.nowcoder.com/practice/0f7e422e12be4a7f9958ca2a82abc775?tpId=107&&tqId=33394&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
����������
�������ڵ�ʱ���Լ�Ҫ˯��ʱ��k����λ��minute�����м��ÿո�ֿ���

�����ʽ��hour:minute k(��hour��minute��ֵΪ1������Ϊ1��������01)

(0 �� hour �� 23��0 �� minute �� 59��1 �� k �� 109)

���������
����ÿ�����룬�������Ӧ���趨��ʱ�̣������ʽΪ��׼ʱ�̱�ʾ������ʱ�ͷֶ�������λ��ʾ��λ��������ǰ��0���룩��
*/


#include <stdio.h>
//1.���Է��ӵ��ܺ�Ϊ���
//2.%02d:%02d - ������淶
//3.(hour + (time + minute) / 60)%24 - Ҫ��24Сʱ��Χ��
int main()
{
    int hour = 0, minute = 0;
    int time = 0;
    //����
    scanf("%d:%d %d", &hour, &minute, &time);
    printf("%02d:%02d\n", (hour + (time + minute) / 60) % 24, (time + minute) % 60);
    return 0;
}

/*
�ַ�תASCII��ֵ

����������
һ�У�һ���ַ���
���������
һ�У���������ַ���Ӧ��ASCII�롣

https://www.nowcoder.com/practice/93f4d05a02d9468db424ed4316bfc8fd?tpId=107&&tqId=33297&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
*/

#include <stdio.h>

int main()
{
    char ch = getchar();
    printf("%d", ch);
    return 0;
}