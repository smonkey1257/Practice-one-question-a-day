#define _CRT_SECURE_NO_WARNINGS 1

/*
题目：一元多项式的乘法与加法运算

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入用例：
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1

输出用例：
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//创建多项式节点
typedef struct Polynomial
{
    int coefficient;
    int index;
    struct Polynomial* next;
}Polynomial;

Polynomial* PolynomialInit()
{
    // k 为项数
    int k = 0;
    scanf("%d", &k);

    //对输入的数据用一个链表来存储，返回链表的头指针
    Polynomial* head = NULL, * tail = NULL;

    while (k--)
    {
        //创建新节点放数据
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        scanf("%d %d", &newnode->coefficient, &newnode->index);
        newnode->next = NULL;

        //如果链表为空
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
    //暴力破解，返回新链表
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
    //新链表的头尾指针
    Polynomial* newhead = NULL, * newtail = NULL;
    
    while (curA && curB)
    {
        //新链表节点
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        newnode->next = NULL;
        
        if (curA->index == curB->index)
        {
            //指数相同，系数相加
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
            //A指数 > B指数
            newnode->coefficient = curA->coefficient;
            newnode->index = curA->index;
            curA = curA->next;
        }
        else
        {
            //A指数 < B指数
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

// 单链表打印
void SLPrint(Polynomial* plist)
{
    if (plist == NULL)
    {
        printf("0 0\n");
    }
    else
    {
        //在不为空指针之前
        while (plist)
        {
            printf("%d %d ", plist->coefficient, plist->index);
            plist = plist->next;
        }
    }
    //最后提示空指针并且换行
}
//不需要改动链表，因此不需要二级指针

int main()
{
    //A多项式
    Polynomial* A = PolynomialInit();
    //B多项式
    Polynomial* B = PolynomialInit();
    ////多项式乘积

    Polynomial* Product = PolynomialProduct(A, B);
    ////多项式之和
    Polynomial* sum = PolynomialSum(A, B);
    ////打印
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
//				** 遍历result, 找到插入的位置
//				*/
//				pre = pre->next;
//			}
//
//			if (pre->next == NULL || pre->next->expo != p->expo) {
//				/*
//				** pre->next为NULL时, 元素值为最小, 插在最后作为表尾
//				** 先判断pre->next是否为NULL可以防止后面的判断语句出现对空指针解引用的错误
//				*/
//				p->next = pre->next;
//				pre->next = p;
//			}
//			else {
//				/*
//				** 如果pre->next->expo等于p->expo, 两者为同类型, 合并
//				*/
//				pre->next->coef += p->coef;
//				free(p);
//			}
//		}
//	}
//
//	if (result->next != NULL) {
//		/*
//		** 若结果为零多项式, 此时result为空表
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
//				** 如果没有continue, free之后的p会接在表尾
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
//		** 两个都要判断, 避免在两者都为空指针时对空指针解引用
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
