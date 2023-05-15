#define _CRT_SECURE_NO_WARNINGS 1

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
void Print(List L); /* 细节在此不表 */

List Insert(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Insert(List L, ElementType X)
{
    List newnode = (List)malloc(sizeof(struct Node));
    newnode->Next = NULL;
    newnode->Data = X;

    List prev = L;
    List cur = L->Next;

    while (cur && cur->Data < X)
    {
        cur = cur->Next;
        prev = prev->Next;
    }
    newnode->Next = cur;
    prev->Next = newnode;

    return L;
}