#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

ElementType Find(List L, int m);

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L, m));
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */

ElementType Find(List L, int m)
{
    //空链表
    if (!L->Next)
        return ERROR;
    List fast = L->Next;
    List slow = L->Next;
    //fast先走（m-1）步
    for (int i = m - 1; i > 0; i--)
    {
        fast = fast->Next;
        //m过大
            if (!fast)
                return ERROR;
    }
    while (fast->Next)
    {
        fast = fast->Next;
        slow = slow->Next;
    }
    return slow->Data;
}