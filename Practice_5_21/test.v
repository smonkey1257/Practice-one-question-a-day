#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList( List L ); /* ����ʵ�֣�ϸ�ڲ��� */
List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
//ԭ��˼·�ǽ�ѭ������Ҫɾ�������������ͽ������ڵ�Ԫ�شӸ�λ�ÿ�ʼ�������������ǰ���ǵ������ڽ�β���±�һֱ�ڱ䣬ʵ��������Ϊ����

//˼·2��ѭ���������齫�������ڵ�Ԫ�شӵ�һ��λ�ÿ�ʼ�ţ�������û��Ԫ��Ϊ��������Ԫ�أ�L->Last == -1,��ʾ���ݱ�ɾ����
List Delete( List L, ElementType minD, ElementType maxD )
{
    int i = 0, k = 0;
    while(k <= L->Last)
    {
        if(L->Data[k] <= minD || L->Data[k] >= maxD)
            L->Data[i++] = L->Data[k];
        k++;
    }
    L->Last = i-1;
    return L;
}