/* 
�ж�������

��Ŀ�ж����������ݣ�ÿһ����������a��b��c(0<a,b,c<1000)����Ϊ�����ε������ߣ��ÿո�ָ���

���ÿ���������ݣ����ռһ�У�����ܹ��������Σ�
�ȱ��������������Equilateral triangle!����
�����������������Isosceles triangle!����
������������������Ordinary triangle!����
��֮�����Not a triangle!����
*/
//��Ŀ����
https://www.nowcoder.com/practice/689ec1e742394e09b1059556fc167b65?tpId=107&&tqId=33332&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking

#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    //��������
    while (scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        //�ж��ǲ���������
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            //�ȱ�������
            if (a == b && b == c)
            {
                printf("Equilateral triangle!\n");
            }
            //����������
            else if (a == b || b == c || a == c)
            {
                printf("Isosceles triangle!\n");
            }
            else
            {
                printf("Ordinary triangle!\n");
            }
        }
        else
        {
            printf("Not a triangle!\n");
        }
    }

    return 0;
}
