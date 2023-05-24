#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
typedef int DataType;                                // 定义具体数据类型

#define LISTSIZE 100                                // LISTSIZE 表示顺序表可能的最大数据元素数目

/****** 顺序表存储结构 ******/
typedef struct
{
    DataType list[LISTSIZE];
    int length;
}SqList;


/****** 初始化顺序表 ******/
int InitList(SqList* L)                // L为指向顺序表的指针
{
    L->length = 0;
    return 1;
}

/****** 求顺序表表长 ******/
int ListLenth(SqList L)                // L为顺序表
{
    return L.length;
}

/****** 判断顺序表是否为空 ******/
int ListEmpty(SqList L)                // L为顺序表
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

/****** 向顺序表插入元素 ******/
int ListInsert(SqList* L, int pos, DataType item)
{                                    // L为指向顺序表的指针，pos为插入位置，item为待插入的数据元素
    int i;

    if (L->length >= LISTSIZE)    // 判断顺序表是否已满
    {
        printf("顺序表已满，无法插入\n");
        return 0;
    }

    if (pos <= 0 || pos > L->length + 1)
    {                                // 检查元素插入位置是否在顺序表里
        printf("插入位置不合法\n");
        return 0;
    }

    for (i = L->length - 1; i >= pos - 1; i--)
    {                                // 移动数据元素
        L->list[i + 1] = L->list[i];
    }

    L->list[pos - 1] = item;        // 插入元素
    L->length++;                    // 表长加一

    return 1;
}


/****** 遍历顺序表 ******/
int TraverList(SqList L)            // L为顺序表
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.list[i]);
    }
    printf("\n");
    return 1;
}

void swap(SqList* L, int i, int j)
{
    DataType temp = L->list[i];
    L->list[i] = L->list[j];
    L->list[j] = temp;
}
void BubbleSort(SqList* L);
int main()
{
    SqList L;
    DataType x;
    char ch;
    int pos = 1;
    InitList(&L);
    do
    {
        scanf("%d", &x);  // 某些编译器要求此处改为scanf_s
        ListInsert(&L, pos++, x);
    } while ((ch = getchar()) != '\n');
    BubbleSort(&L);
    printf("The sorted List is\n");
    TraverList(L);
    return 0;
}
/* 请在这里填写答案 */

void BubbleSort(SqList* L)
{
    for (int i = 0; i < L->length - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < L->length - 1 - i; j++)
        {
            if (L->list[j] > L->list[j + 1])
            {
                swap(L, j, j + 1);
                flag = 0;
            }
        }

        if (flag == 1)
            break;

        //打印一趟的结果
        for (int j = 0; j < L->length; j++)
        {
            printf("%d ", L->list[j]);
        }
        printf("\n");
    }
}