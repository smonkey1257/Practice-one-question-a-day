#define _CRT_SECURE_NO_WARNINGS 1

/*
ϰ��2.5 ���������������еĺϲ�
���� 15
���� DS�γ���
��λ �㽭��ѧ
����Ҫ��ʵ��һ�������������������ʾ�ĵ����������кϲ�Ϊһ���ǵݼ����������С�

L1��L2�Ǹ����Ĵ�ͷ���ĵ���������洢�������ǵ�������ģ�
����MergeҪ��L1��L2�ϲ�Ϊһ���ǵݼ����������С�Ӧֱ��ʹ��ԭ�����еĽ�㣬���ع鲢��Ĵ�ͷ��������ͷָ�롣
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

List Read(); /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲������������NULL */

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

/* ��Ĵ��뽫��Ƕ������ */

List Merge(List L1, List L2)
{
    //�ϲ���������ڱ�λ���
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List cur = L;

    while (L1->Next && L2->Next)
    {
        //�Ƚϣ�С�Ľ��ı����ӹ�ϵ���������L�Ľ��
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

    //ѭ������֮����һ��Ϊ��
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