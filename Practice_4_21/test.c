#define _CRT_SECURE_NO_WARNINGS 1

/*
��һ�⣺С������ͣ�https://www.nowcoder.com/practice/ce0b2eacd3d04647831358c2876e44ff?tpId=107&&tqId=33393&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking��

����
С��������Ӵ�����ͷ��Ŧ����������Ľ��������С���ֺܱ���������������

����������
����һ��������n  (1 �� n �� 109)

���������
���һ��ֵ��Ϊ��ͽ����

ʾ��1
���룺1
�����1
*/

#include <stdio.h>

int main()
{
    //(1 �� n �� 109) - ���Ӧ����һ���ܴ������
    int n = 0;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    printf("%lld\n", sum);
    return 0;
}

/*
* �ڶ��⣺С�����������(https://www.nowcoder.com/practice/ae6a21920cac4f9184c8ecfcc87f89b9?tpId=107&&tqId=33404&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking)
* 
* ������С���ֻ��4������������������ҵ���������
* ����������
* һ�У�4���������ÿո�ֿ���
* 
* ���������
* һ�У�һ��������Ϊ�����4������������������
* 
* ʾ��1
* ���룺5 8 2 5
* �����8

*/

#include <stdio.h>

//�ظ�����һ����������������
int main()
{
    int num = 0;
    scanf("%d", &num);
    int max = num;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &num);
        if (max < num)
            max = num;
    }
    printf("%d\n", max);
    return 0;
}

/*
�����⣺�ж��ǲ�����ĸ��https://www.nowcoder.com/practice/91a588dd4cd244bfa616f17603ec123c?tpId=107&&tqId=33328&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking��

����
KiKi���ж�������ַ��ǲ�����ĸ����������ʵ�֡�

����������
�������룬ÿһ������һ���ַ���
���������
���ÿ�����룬�������ռһ�У��ж������ַ��Ƿ�Ϊ��ĸ���������������������
ʾ��1
���룺
A
6
�����
A is an alphabet.
6 is not an alphabet.
*/

#include <stdio.h>

int main()
{
    char ch = 0;
    while ((ch = getchar()) != EOF)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            printf("%c is an alphabet.\n", ch);
        }
        else
        {
            printf("%c is not an alphabet.\n", ch);
        }
        //���и���
        getchar();
    }
    return 0;
}

/*
�����⣺������https://www.nowcoder.com/practice/5d7dfd405e5f4e4fbfdff6862c46b751?tpId=107&&tqId=33318&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking��

����
KiKi�ǳ�ϲ����������һ�ҵ�����������һ���·������˽⵽��
��������ǡ�˫11����11��11�գ�������·���7�ۣ�
��˫12�� ��12��12�գ�������·���8�ۣ�
������Ż�ȯ���Զ����50Ԫ���Ż�ȯֻ����˫11��˫12ʹ�ã�����KiKi����������Ǯ����

���ݷ�Χ���·��۸����� 1��val��100000

����������
һ�У��ĸ����֣���һ������ʾС�����е��·��۸�
�ڶ��͵����������ֱ��ʾ������·ݡ���������ڡ�
���ĸ�������ʾ�Ƿ����Ż�ȯ�����Ż�ȯ��1��ʾ�����Ż�ȯ��0��ʾ���� ע���������ڱ�ֻ֤�С�˫11���͡�˫12����
���������
һ�У�С��ʵ�ʻ���Ǯ����������λС����������ʾ����Ҫָ���̼ҵ�����Ǯ��
*/

#include <stdio.h>

int main()
{
    float val = 0.0f;
    int month = 0;
    int day = 0;
    int flag = 0;

    //����
    scanf("%f %d %d %d", &val, &month, &day, &flag);
    //���ջ���
    if (month == 11 && flag == 1)
    {
        val = 0.7 * val - 50;
    }
    else if (month == 11 && flag != 1)
    {
        val = 0.7 * val;
    }
    else if (month == 12 && flag == 1)
    {
        val = 0.8 * val - 50;
    }
    else
    {
        val = 0.8 * val;
    }

    if (val <= 0)
        val = 0.0f;

    printf("%0.2f\n", val);
    return 0;
}