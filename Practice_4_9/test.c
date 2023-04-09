/* 
判断三角形

题目有多组输入数据，每一行输入三个a，b，c(0<a,b,c<1000)，作为三角形的三个边，用空格分隔。

针对每组输入数据，输出占一行，如果能构成三角形，
等边三角形则输出“Equilateral triangle!”，
等腰三角形则输出“Isosceles triangle!”，
其余的三角形则输出“Ordinary triangle!”，
反之输出“Not a triangle!”。
*/
//题目链接
https://www.nowcoder.com/practice/689ec1e742394e09b1059556fc167b65?tpId=107&&tqId=33332&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking

#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    //多组输入
    while (scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        //判断是不是三角形
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            //等边三角形
            if (a == b && b == c)
            {
                printf("Equilateral triangle!\n");
            }
            //等腰三角形
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
