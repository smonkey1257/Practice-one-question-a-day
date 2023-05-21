#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
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

/* 你的代码将被嵌在这里 */
//原本思路是将循环遍历要删除的数，遇到就将数组内的元素从该位置开始将后面的数据往前覆盖但是由于结尾的下标一直在变，实现起来较为复杂

//思路2：循环遍历数组将非区间内的元素从第一个位置开始放，如果最后没有元素为非区间内元素，L->Last == -1,表示数据被删空了
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