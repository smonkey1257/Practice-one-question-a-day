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
{ // ��ʼ������������ͷ���
    *head = (LinkList)malloc(sizeof(LNode));
    if (!head)
    {
        printf("��ʼ���������!\n");
        return 0;
    }
    (*head)->next = NULL;
    return 1;
}

PNode LinkListInsert(LinkList h, int pos, DataType x)
{ // �ڵ�����h�ĵ�pos��λ�ò���xֵ��Ԫ��
    PNode p = h, q;
    int i = 0;
    while (p && i < pos - 1)
    {
        p = p->next;
        i++;
    }
    if (!p || i > pos - 1)
    {
        printf("����λ�ò��Ϸ�!\n");
        return NULL;
    }
    q = (PNode)malloc(sizeof(LNode));
    if (!q)
    {
        printf("���������½��\n");
        return NULL;
    }
    q->data = x;
    q->next = p->next;
    p->next = q;
    return q;
}

void DestroyLinkList(LinkList h)
{ // ���ٵ�����
    PNode p = h->next;
    while (h)
    {
        p = h;
        h = h->next;
        free(p);
    }
}

void TraverseLinkList(LinkList h)
{ // ����������
    PNode p = h->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int BnotinA(LinkList a, LinkList b)
{ // ������B�������Ƿ���������A
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

// ����Ҫ����
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
        scanf("%d", &x);  // ĳЩ������Ҫ��˴���Ϊscanf_s
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
        printf("������B��C�����������ڵ�����A\n");
    }
    else if ((BnotinA(aa1, bb) != 1) && (BnotinA(aa1, cc) != 1))
    {
        printf("������B��C�����������ڵ�����A\n");
    }
    printf("������B��\n");
    TraverseLinkList(bb);
    printf("������C��\n");
    TraverseLinkList(cc);
    DestroyLinkList(aa);
    DestroyLinkList(bb);
    DestroyLinkList(cc);
    return 0;
}
/* ��Ĵ���д�ڴ˴� */
void SplitList(LinkList a, LinkList* b, LinkList* c)
{
    LinkList pb = *b, pc = *c;
    while (a->next)
    {
        //�����������b
        if (a->next->data < 0)
        {
            pb->next = a->next;
            a->next = a->next->next;
            pb = pb->next;
            pb->next = NULL;

        }
        //�����������c
        else if(a->next->data > 0)
        {
            pc->next = a->next;
            a->next = a->next->next;
            pc = pc->next;
            pc->next = NULL;

        }
        //0���
        else
            a->next = a->next->next;
    }
}
