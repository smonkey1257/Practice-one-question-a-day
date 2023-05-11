#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node* next;
}LNode, * PNode, * LinkList;

int InitLinkList(LinkList* head)
{ // 初始化单链表，开辟头结点
    *head = (LinkList)malloc(sizeof(LNode));
    if (!head)
    {
        printf("初始化链表错误!\n");
        return 0;
    }
    (*head)->next = NULL;
    return 1;
}

PNode LinkListInsert(LinkList h, int pos, DataType x)
{ // 在单链表h的第pos个位置插入x值的元素
    PNode p = h, q;
    int i = 0;
    while (p && i < pos - 1)
    {
        p = p->next;
        i++;
    }
    if (!p || i > pos - 1)
    {
        printf("插入位置不合法!\n");
        return NULL;
    }
    q = (PNode)malloc(sizeof(LNode));
    if (!q)
    {
        printf("不能生成新结点\n");
        return NULL;
    }
    q->data = x;
    q->next = p->next;
    p->next = q;
    return q;
}

void DestroyLinkList(LinkList h)
{ // 销毁单链表
    PNode p = h->next;
    while (h)
    {
        p = h;
        h = h->next;
        free(p);
    }
}

void TraverseLinkList(LinkList h)
{ // 遍历单链表
    PNode p = h->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int BnotinA(LinkList a, LinkList b)
{ // 判链表B的链点是否来自链表A
    PNode pb = b->next;
    PNode pa = a->next;
    if (!pa)
    {
        return 1;
    }
    if (!pb)
    {
        return 1;
    }
    while (pa)
    {
        if ((DataType)pb != pa->data)
        {
            pa = pa->next;
            continue;
        }
        return 0;
    }
    return 1;
}

// 本题要求函数
void SplitList(LinkList a, LinkList* b, LinkList* c);

int main()
{
    LinkList aa, aa1, bb, cc;
    DataType x;
    char ch;
    int pos = 1;
    PNode pa = NULL;
    InitLinkList(&aa);
    InitLinkList(&aa1);
    InitLinkList(&bb);
    InitLinkList(&cc);
    do
    {
        scanf("%d", &x);  // 某些编译器要求此处改为scanf_s
        pa = LinkListInsert(aa, pos, x);
        if (pa != NULL)
        {
            LinkListInsert(aa1, pos, (DataType)pa);
        }
        pos++;
    } while ((ch = getchar()) != '\n');
    SplitList(aa, &bb, &cc);
    if ((bb->next == NULL && BnotinA(aa1, cc) != 1) || (cc->next == NULL && BnotinA(aa1, bb) != 1))
    {
        printf("单链表B和C的链点来自于单链表A\n");
    }
    else if ((BnotinA(aa1, bb) != 1) && (BnotinA(aa1, cc) != 1))
    {
        printf("单链表B和C的链点来自于单链表A\n");
    }
    printf("单链表B是\n");
    TraverseLinkList(bb);
    printf("单链表C是\n");
    TraverseLinkList(cc);
    DestroyLinkList(aa);
    DestroyLinkList(bb);
    DestroyLinkList(cc);
    return 0;
}
/* 你的代码写在此处 */
void SplitList(LinkList a, LinkList* b, LinkList* c)
{
    LinkList pb = *b, pc = *c;
    while (a->next)
    {
        //负数结点链接b
        if (a->next->data < 0)
        {
            pb->next = a->next;
            a->next = a->next->next;
            pb = pb->next;
            pb->next = NULL;

        }
        //正数结点链接c
        else if(a->next->data > 0)
        {
            pc->next = a->next;
            a->next = a->next->next;
            pc = pc->next;
            pc->next = NULL;

        }
        //0结点
        else
            a->next = a->next->next;
    }
}
