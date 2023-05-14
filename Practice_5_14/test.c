#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum { false, true } bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList(List L); /* ����ʵ�֣�ϸ�ڲ��� */
bool Insert(List L, ElementType X);

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if (Insert(L, X) == false)
        printf("Insertion failed.\n");
    PrintList(L);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */

bool Insert(List L, ElementType X)
{
    //�ж�˳����Ƿ���
    if (MAXSIZE - 1 == L->Last)
        return false;
    //�жϱ����Ƿ��Ѵ���
    int index = 0;
    for (int i = 0; i <= L->Last; i++)
    {
        if (L->Data[i] == X)
            return false;
        else if (L->Data[i] < X)
        {
            index = i;
            break;
        }
    }
    //������ĩβ
    if (L->Data[L->Last] > X)
    {
        L->Data[L->Last + 1] = X;
        L->Last++;
    }
    else
    {    //�ڱ��н���Ų�����ݵĲ���
        for (int i = L->Last; i >= index; i--)
        {
            L->Data[i + 1] = L->Data[i];
        }
        L->Data[index] = X;
        L->Last += 1;
    }
    return true;
}