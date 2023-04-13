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
    int coefficient;//系数
    int index;      //指数
    struct Polynomial* next;
}Polynomial;

//建立多项式链表，返回多项式链表的头指针
Polynomial* PolynomialInit()
{
    // k 为项数
    int k = 0;
    scanf("%d", &k);

    //多项式链表的头尾指针，尾指针用于维护不用找尾节点
    Polynomial* head = NULL, * tail = NULL;

    while (k--)
    {
        //创建新节点放数据
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        (void)scanf("%d %d", &newnode->coefficient, &newnode->index);
        newnode->next = NULL;

        if (head == NULL)
        {
            //头指针为空->给第一个节点
            head = tail = newnode;
        }
        else
        {
            //链接新节点
            tail->next = newnode;
            tail = tail->next;
        }
    }
    return head;
}


// 单链表打印
void SLPrint(Polynomial* plist)
{
    if (plist == NULL)
    {
        printf("0 0");
    }
    else
    {
        //在不为空指针之前
        while (plist)
        {
            if (!plist->next)
                break;
            printf("%d %d ", plist->coefficient, plist->index);
            plist = plist->next;
        }
        printf("%d %d", plist->coefficient, plist->index);
    }
}

//计算多项式的乘积，返回一个新链表
/*
* 乘法不用考虑相乘系数为0的情况，但乘法需要考虑顺序和同类项合并的问题。
*/
Polynomial* PolynomialMult(Polynomial* A, Polynomial* B)
{
    Polynomial* curA = A;
    Polynomial* curB = B;
    //新链表的头节点
    Polynomial* new = (Polynomial*)malloc(sizeof(Polynomial));
    new->next = NULL;
    Polynomial* cur = NULL;
    
    for (curA = A; curA != NULL; curA = curA->next)
    {
        for (curB = B; curB != NULL; curB = curB->next)
        {
            //相乘之后的多项式节点
            Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
            newnode->coefficient = curA->coefficient * curB->coefficient;
            newnode->index = curA->index + curB->index;
            newnode->next = NULL;
            
            if (newnode->coefficient == 0)
            {
                continue;
            }

            cur = new;
            //把这个节点插入到新的链表上（1.指数降序 2.合并同类项 3.系数为0的节点不链接在链表上 4.）

            while (cur->next != NULL && cur->next->index > newnode->index)
            {
                //当循环结束，有两种可能：
                //1.cur->next->index < newnode->index 
                //2.cur->next->index == newnode->index
                cur = cur->next;
            }

            if (cur->next == NULL || cur->next->index != newnode->index)
            {
                /*
                ** pre->next为NULL时, 元素值为最小, 插在最后作为表尾
                ** 先判断pre->next是否为NULL可以防止后面的判断语句出现对空指针解引用的错误
                */
                newnode->next = cur->next;
                cur->next = newnode;
            }
            else
            {
                //2.cur->next->index == newnode->index
                cur->next->index += newnode->index;
                free(newnode);
            }
        }
    }
    return new->next;
}

//计算多项式之和，返回一个新链表
//题目给出的输入已经按照降幂顺序排列好，相加时不需要考虑顺序的问题，同时加法也不需要考虑同类项合并，
//但加法需要考虑 系数互为相反数的项相加为0的情况。
Polynomial* PolynomialSum(Polynomial* A, Polynomial* B)
{
    Polynomial* curA = A;
    Polynomial* curB = B;

    /*
    ** 不用考虑顺序问题，不用每次都遍历，直接维护一个尾指针就行
    */
    Polynomial* new = NULL;
    Polynomial* tail = new;

    while (curA && curB)
    {
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        newnode->next = NULL;

        if (curA->index == curB->index)
        {
            if (curA->coefficient + curB->coefficient)//系数和不为零
            {
                newnode->coefficient = curA->coefficient + curB->coefficient;
                newnode->index = curA->index;
            }
            else //系数和为0
            {
                //不进行链接节点，直接开始下一次循环
                free(newnode);
                curA = curA->next;
                curB = curB->next;
                continue;
            }
            curA = curA->next;
            curB = curB->next;
        }
        else if (curA->index > curB->index)
        {
            if (curB->coefficient == 0)
                curB = curB->next;
            
            newnode->coefficient = curA->coefficient;
            newnode->index = curA->index;
            curA = curA->next;
        }
        else //curA->index < curB->index
        {
            if (curA->coefficient == 0)
                curA = curA->next;

            newnode->coefficient = curB->coefficient;
            newnode->index = curB->index;
            curB = curB->next;
        }

        //执行链接节点
        if (new == NULL)
        {
            new = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    //出循环后一方为空，一方不为空
    if (curA)
    {
        if (tail)
            tail->next = curA;
        else
            new = curA;
    }
    if (curB)
    {
        if (tail)
            tail->next = curB;
        else
            new = curB;
    }
    return new;

}


int main()
{
    //A多项式
    Polynomial* A = PolynomialInit();
    
    //B多项式
    Polynomial* B = PolynomialInit();
    
    ////多项式乘积
    Polynomial* Product = PolynomialMult(A, B);
    
    ////多项式之和
    Polynomial* sum = PolynomialSum(A, B);
    
    ////打印
    SLPrint(Product);
    printf("\n");
    SLPrint(sum);
    return 0;
}
