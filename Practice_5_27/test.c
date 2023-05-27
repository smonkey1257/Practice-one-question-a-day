#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
typedef int DataType;                                // ���������������

#define LISTSIZE 100                                // LISTSIZE ��ʾ˳�����ܵ��������Ԫ����Ŀ

/****** ˳���洢�ṹ ******/
typedef struct
{
    DataType list[LISTSIZE];
    int length;
}SqList;


/****** ��ʼ��˳��� ******/
int InitList(SqList* L)                // LΪָ��˳����ָ��
{
    L->length = 0;
    return 1;
}

/****** ��˳���� ******/
int ListLenth(SqList L)                // LΪ˳���
{
    return L.length;
}

/****** �ж�˳����Ƿ�Ϊ�� ******/
int ListEmpty(SqList L)                // LΪ˳���
{
    if (L.length <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/****** ��˳������Ԫ�� ******/
int ListInsert(SqList* L, int pos, DataType item)
{                                    // LΪָ��˳����ָ�룬posΪ����λ�ã�itemΪ�����������Ԫ��
    int i;

    if (L->length >= LISTSIZE)    // �ж�˳����Ƿ�����
    {
        printf("˳����������޷�����\n");
        return 0;
    }

    if (pos <= 0 || pos > L->length + 1)
    {                                // ���Ԫ�ز���λ���Ƿ���˳�����
        printf("����λ�ò��Ϸ�\n");
        return 0;
    }

    for (i = L->length - 1; i >= pos - 1; i--)
    {                                // �ƶ�����Ԫ��
        L->list[i + 1] = L->list[i];
    }

    L->list[pos - 1] = item;        // ����Ԫ��
    L->length++;                    // ����һ

    return 1;
}


/****** ����˳��� ******/
int TraverList(SqList L)            // LΪ˳���
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.list[i]);
    }
    printf("\n");
    return 1;
}
void InsertSort(SqList* L);
int main()
{
    SqList L;
    DataType x;
    char ch;
    int pos = 1;
    InitList(&L);
    do
    {
        scanf("%d", &x); // ĳЩ������Ҫ��˴���Ϊscanf_s
        ListInsert(&L, pos++, x);
    } while ((ch = getchar()) != '\n');
    InsertSort(&L);
    printf("The sorted List is\n");
    TraverList(L);
    return 0;
}

/* ����������д�� */
void InsertSort(SqList* L)
{
    int tmp = 0;
    int j = 0;
    for (int i = 1; i < L->length; i++)
    {
        //tmp��Ҫ�����ֵ
        tmp = L->list[i];
        for (j = i; j > 0 && L->list[j - 1] > tmp; j--)
        {
            L->list[j] = L->list[j - 1];
        }
        //���ҵ����ʵ�λ��
        L->list[j] = tmp;

        TraverList(*L);
    }
}