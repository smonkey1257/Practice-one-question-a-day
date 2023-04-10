#define _CRT_SECURE_NO_WARNINGS 1

/*
题目：一元多项式的乘法与加法运算

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入用例：
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1

输出用例：
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//创建多项式节点
typedef struct Polynomial
{
    int coefficient;
    int index;
    struct Polynomial* next;
}Polynomial;

Polynomial* PolynomialInit()
{
    // k 为项数
    int k = 0;
    scanf("%d", &k);

    //对输入的数据用一个链表来存储，返回链表的头指针
    Polynomial* head = NULL, * tail = NULL;

    while (k--)
    {
        //创建新节点放数据
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        scanf("%d %d", &newnode->coefficient, &newnode->index);
        newnode->next = NULL;

        //如果链表为空
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
    }
    return head;
}

Polynomial* PolynomialProduct(Polynomial* A, Polynomial* B)
{
    //暴力破解，返回新链表
    Polynomial* newhead = NULL, *newtail = NULL;
    Polynomial* Ahead = A, * Atail = A;
    Polynomial* Bhead = B, * Btail = B;

    while (Btail)
    {
        while (Atail)
        {
            Polynomial* tmp = (Polynomial*)malloc(sizeof(Polynomial));
            tmp->coefficient = Atail->coefficient * Btail->coefficient;
            tmp->index = Atail->index + Btail->index;
            tmp->next = NULL;
            if (newhead == NULL)
            {
                newhead = newtail = tmp;
            }
            else
            {
                newtail->next = tmp;
                newtail = newtail->next;
            }
            Atail = Atail->next;
        }
        Atail = Ahead;
        Btail = Btail->next;
    }
    return newhead;
}


// 单链表打印
void SLPrint(Polynomial* plist)
{
    //在不为空指针之前
    while (plist)
    {
        printf("%d %d ", plist->coefficient, plist->index);
        plist = plist->next;
    }
    //最后提示空指针并且换行
    printf("-> NULL\n");
}
//不需要改动链表，因此不需要二级指针

int main()
{
    //A多项式
    Polynomial* A = PolynomialInit();
    //B多项式
    Polynomial* B = PolynomialInit();
    ////多项式乘积

    Polynomial* Product = PolynomialProduct(A, B);
    ////多项式之和
    //Polynomial* sum = PolynomialSum(A, B);
    ////打印
    SLPrint(Product);

    return 0;
}