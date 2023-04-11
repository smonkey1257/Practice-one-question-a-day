#define _CRT_SECURE_NO_WARNINGS 1

/*
��Ŀ��һԪ����ʽ�ĳ˷���ӷ�����

�����ʽ:
�����2�У�ÿ�зֱ��ȸ�������ʽ������ĸ���������ָ���ݽ���ʽ����һ������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���

�����ʽ:
�����2�У��ֱ���ָ���ݽ���ʽ����˻�����ʽ�Լ��Ͷ���ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո������ʽӦ���0 0��

����������
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1

���������
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��������ʽ�ڵ�
typedef struct Polynomial
{
    int coefficient;
    int index;
    struct Polynomial* next;
}Polynomial;

Polynomial* PolynomialInit()
{
    // k Ϊ����
    int k = 0;
    scanf("%d", &k);

    //�������������һ���������洢�����������ͷָ��
    Polynomial* head = NULL, * tail = NULL;

    while (k--)
    {
        //�����½ڵ������
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        scanf("%d %d", &newnode->coefficient, &newnode->index);
        newnode->next = NULL;

        //�������Ϊ��
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
    }
    return head;
}

Polynomial* PolynomialMult(Polynomial* A, Polynomial* B)
{

}

Polynomial* PolynomialProduct(Polynomial* A, Polynomial* B)
{
    //�����ƽ⣬����������
    Polynomial* newhead = NULL, *newtail = NULL;
    Polynomial* Ahead = A, * Atail = A;
    Polynomial* Bhead = B, * Btail = B;

    while (Btail)
    {
        while (Atail)
        {
            Polynomial* tmp = (Polynomial*)malloc(sizeof(Polynomial));
            tmp->coefficient = Atail->coefficient * Btail->coefficient;
            tmp->index = Atail->index + Btail->index;
            tmp->next = NULL;
            if (tmp->coefficient == 0)
            {
                tmp->index = 0;
                free(tmp);
                tmp = NULL;
            }
            if (newhead == NULL)
            {
                newhead = newtail = tmp;
            }
            else
            {
                newtail->next = tmp;
                if(tmp)
                    newtail = newtail->next;
            }
            Atail = Atail->next;
        }
        Atail = Ahead;
        Btail = Btail->next;
    }
    return newhead;
}

Polynomial* PolynomialSum(Polynomial* A, Polynomial* B)
{
    Polynomial* curA = A;
    Polynomial* curB = B;
    //�������ͷβָ��
    Polynomial* newhead = NULL, * newtail = NULL;
    
    while (curA && curB)
    {
        //������ڵ�
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        newnode->next = NULL;
        
        if (curA->index == curB->index)
        {
            //ָ����ͬ��ϵ�����
            newnode->coefficient = curA->coefficient + curB->coefficient;
            newnode->index = curA->index;
            curA = curA->next;
            curB = curB->next;
            if (newnode->coefficient == 0)
            {
                free(newnode);
                newnode = NULL;
            }
        }
        else if (curA->index > curB->index)
        {
            //Aָ�� > Bָ��
            newnode->coefficient = curA->coefficient;
            newnode->index = curA->index;
            curA = curA->next;
        }
        else
        {
            //Aָ�� < Bָ��
            newnode->coefficient = curB->coefficient;
            newnode->index = curB->index;
            curB = curB->next;
        }
        if (newhead == NULL)
        {
            newhead = newtail = newnode;
        }
        else
        {
            newtail->next = newnode;
            if(newnode)
                newtail = newnode;
        }

    }
    if (curA)
    {
        newtail->next = curA;
    }
    if (curB)
    {
        newtail->next = curB;
    }
    
    return newhead;
}

// �������ӡ
void SLPrint(Polynomial* plist)
{
    if (plist == NULL)
    {
        printf("0 0\n");
    }
    else
    {
        //�ڲ�Ϊ��ָ��֮ǰ
        while (plist)
        {
            printf("%d %d ", plist->coefficient, plist->index);
            plist = plist->next;
        }
    }
    //�����ʾ��ָ�벢�һ���
}
//����Ҫ�Ķ�������˲���Ҫ����ָ��

int main()
{
    //A����ʽ
    Polynomial* A = PolynomialInit();
    //B����ʽ
    Polynomial* B = PolynomialInit();
    ////����ʽ�˻�

    Polynomial* Product = PolynomialProduct(A, B);
    ////����ʽ֮��
    Polynomial* sum = PolynomialSum(A, B);
    ////��ӡ
    SLPrint(Product);
    printf("\n");
    SLPrint(sum);
    return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct _node {
//	int coef;
//	int expo;
//	struct _node* next;
//}linkList;
//
//void
//initList(linkList** l);
//
//void
//createList(linkList* l);
//
//void
//mulList(linkList* l1, linkList* l2);
//
//void
//addList(linkList* l1, linkList* l2);
//
//int
//main(int argc, char** argv)
//{
//	linkList* l1, * l2;
//	initList(&l1);
//	createList(l1);
//	initList(&l2);
//	createList(l2);
//	mulList(l1, l2);
//	addList(l1, l2);
//	return 0;
//}
//
//void
//initList(linkList** l)
//{
//	(*l) = (linkList*)malloc(sizeof(linkList));
//	(*l)->next = NULL;
//}
//
//void
//createList(linkList* l)
//{
//	int n;
//	linkList* tail, * p;
//	tail = l;
//	scanf("%d", &n);
//
//	while (n-- > 0) {
//		p = (linkList*)malloc(sizeof(linkList));
//		scanf("%d%d", &p->coef, &p->expo);
//		tail->next = p;
//		tail = p;
//	}
//	tail->next = NULL;
//}
//
//void
//mulList(linkList* l1, linkList* l2)
//{
//	linkList* p1, * p2;
//	linkList* result, * pre, * p;
//	initList(&result);
//
//	for (p1 = l1->next; p1 != NULL; p1 = p1->next) {
//		for (p2 = l2->next; p2 != NULL; p2 = p2->next) {
//			p = (linkList*)malloc(sizeof(linkList));
//			p->coef = p1->coef * p2->coef;
//			p->expo = p1->expo + p2->expo;
//
//			pre = result;
//			while (pre->next != NULL && pre->next->expo > p->expo) {
//				/*
//				** ����result, �ҵ������λ��
//				*/
//				pre = pre->next;
//			}
//
//			if (pre->next == NULL || pre->next->expo != p->expo) {
//				/*
//				** pre->nextΪNULLʱ, Ԫ��ֵΪ��С, ���������Ϊ��β
//				** ���ж�pre->next�Ƿ�ΪNULL���Է�ֹ������ж������ֶԿ�ָ������õĴ���
//				*/
//				p->next = pre->next;
//				pre->next = p;
//			}
//			else {
//				/*
//				** ���pre->next->expo����p->expo, ����Ϊͬ����, �ϲ�
//				*/
//				pre->next->coef += p->coef;
//				free(p);
//			}
//		}
//	}
//
//	if (result->next != NULL) {
//		/*
//		** �����Ϊ�����ʽ, ��ʱresultΪ�ձ�
//		*/
//		for (p1 = result->next; p1 != NULL; p1 = p2) {
//			if (p1->coef != 0) {
//				printf("%d %d", p1->coef, p1->expo);
//				if (p1->next != NULL) {
//					printf(" ");
//				}
//			}
//			p2 = p1->next;
//			free(p1);
//		}
//	}
//	else {
//		printf("0 0");
//	}
//	free(result);
//	printf("\n");
//}
//
//void
//addList(linkList* l1, linkList* l2)
//{
//	linkList* result, * p, * tail;
//	initList(&result);
//	tail = result;
//
//	l1 = l1->next;
//	l2 = l2->next;
//	while (l1 != NULL && l2 != NULL) {
//		p = (linkList*)malloc(sizeof(linkList));
//		if (l1->expo == l2->expo) {
//			if (l1->coef + l2->coef) {
//				p->coef = l1->coef + l2->coef;
//				p->expo = l1->expo;
//			}
//			else {
//				free(p);
//				l1 = l1->next;
//				l2 = l2->next;
//				continue;
//				/*
//				** ���û��continue, free֮���p����ڱ�β
//				*/
//			}
//			l1 = l1->next;
//			l2 = l2->next;
//		}
//		else if (l1->expo > l2->expo) {
//			p->coef = l1->coef;
//			p->expo = l1->expo;
//			l1 = l1->next;
//		}
//		else {
//			p->coef = l2->coef;
//			p->expo = l2->expo;
//			l2 = l2->next;
//		}
//		if (l1 != NULL || l2 != NULL) {
//			tail->next = p;
//			tail = p;
//		}
//	}
//
//	while (l1 != NULL && l2 == NULL) {
//		/*
//		** ������Ҫ�ж�, ���������߶�Ϊ��ָ��ʱ�Կ�ָ�������
//		*/
//		p = (linkList*)malloc(sizeof(linkList));
//		p->coef = l1->coef;
//		p->expo = l1->expo;
//		l1 = l1->next;
//		tail->next = p;
//		tail = p;
//	}
//
//	while (l2 != NULL && l1 == NULL) {
//		p = (linkList*)malloc(sizeof(linkList));
//		p->coef = l2->coef;
//		p->expo = l2->expo;
//		l2 = l2->next;
//		tail->next = p;
//		tail = p;
//	}
//	tail->next = NULL;
//
//	if (result->next != NULL) {
//		for (p = result->next; p != NULL; p = tail) {
//			printf("%d %d", p->coef, p->expo);
//			if (p->next != NULL) {
//				printf(" ");
//			}
//			tail = p->next;
//			free(p);
//		}
//	}
//	else {
//		printf("0 0");
//	}
//}
