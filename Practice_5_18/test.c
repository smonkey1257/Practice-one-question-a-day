#define _CRT_SECURE_NO_WARNINGS 1

/*
习题2.5 两个有序链表序列的合并
分数 15
作者 DS课程组
单位 浙江大学
本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；
函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2)
{
    //合并后链表的哨兵位结点
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List cur = L;

    while (L1->Next && L2->Next)
    {
        //比较，小的结点改变链接关系，变成链表L的结点
        if (L1->Next->Data < L2->Next->Data)
        {
            cur->Next = L1->Next;
            L1->Next = L1->Next->Next;
            //cur->Next->Next = NULL;
            cur = cur->Next;
        }
        else
        {
            cur->Next = L2->Next;
            L2->Next = L2->Next->Next;
            //cur->Next->Next = NULL;
            cur = cur->Next;
        }
    }

    //循环结束之后有一方为空
    if (L1->Next)
    {
        cur->Next = L1->Next;
        L1->Next = NULL;
    }

    if (L2->Next)
    {
        cur->Next = L2->Next;
        L2->Next = NULL;
    }

    return L;
}