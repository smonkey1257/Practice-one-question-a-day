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
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList(List L); /* 裁判实现，细节不表 */
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

/* 你的代码将被嵌在这里 */

bool Insert(List L, ElementType X)
{
    //判断顺序表是否满
    if (MAXSIZE - 1 == L->Last)
        return false;
    //判断表中是否已存在
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
    //插入在末尾
    if (L->Data[L->Last] > X)
    {
        L->Data[L->Last + 1] = X;
        L->Last++;
    }
    else
    {    //在表中进行挪动数据的插入
        for (int i = L->Last; i >= index; i--)
        {
            L->Data[i + 1] = L->Data[i];
        }
        L->Data[index] = X;
        L->Last += 1;
    }
    return true;
}