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

List Read(); /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲��� */

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

/* ��Ĵ��뽫��Ƕ������ */

ElementType Find(List L, int m)
{
    //������
    if (!L->Next)
        return ERROR;
    List fast = L->Next;
    List slow = L->Next;
    //fast���ߣ�m-1����
    for (int i = m - 1; i > 0; i--)
    {
        fast = fast->Next;
        //m����
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