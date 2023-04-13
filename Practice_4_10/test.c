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
    int coefficient;//ϵ��
    int index;      //ָ��
    struct Polynomial* next;
}Polynomial;

//��������ʽ�������ض���ʽ�����ͷָ��
Polynomial* PolynomialInit()
{
    // k Ϊ����
    int k = 0;
    scanf("%d", &k);

    //����ʽ�����ͷβָ�룬βָ������ά��������β�ڵ�
    Polynomial* head = NULL, * tail = NULL;

    while (k--)
    {
        //�����½ڵ������
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        (void)scanf("%d %d", &newnode->coefficient, &newnode->index);
        newnode->next = NULL;

        if (head == NULL)
        {
            //ͷָ��Ϊ��->����һ���ڵ�
            head = tail = newnode;
        }
        else
        {
            //�����½ڵ�
            tail->next = newnode;
            tail = tail->next;
        }
    }
    return head;
}


// �������ӡ
void SLPrint(Polynomial* plist)
{
    if (plist == NULL)
    {
        printf("0 0");
    }
    else
    {
        //�ڲ�Ϊ��ָ��֮ǰ
        while (plist)
        {
            if (!plist->next)
                break;
            printf("%d %d ", plist->coefficient, plist->index);
            plist = plist->next;
        }
        printf("%d %d", plist->coefficient, plist->index);
    }
}

//�������ʽ�ĳ˻�������һ��������
/*
* �˷����ÿ������ϵ��Ϊ0����������˷���Ҫ����˳���ͬ����ϲ������⡣
*/
Polynomial* PolynomialMult(Polynomial* A, Polynomial* B)
{
    Polynomial* curA = A;
    Polynomial* curB = B;
    //�������ͷ�ڵ�
    Polynomial* new = (Polynomial*)malloc(sizeof(Polynomial));
    new->next = NULL;
    Polynomial* cur = NULL;
    
    for (curA = A; curA != NULL; curA = curA->next)
    {
        for (curB = B; curB != NULL; curB = curB->next)
        {
            //���֮��Ķ���ʽ�ڵ�
            Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
            newnode->coefficient = curA->coefficient * curB->coefficient;
            newnode->index = curA->index + curB->index;
            newnode->next = NULL;
            
            if (newnode->coefficient == 0)
            {
                continue;
            }

            cur = new;
            //������ڵ���뵽�µ������ϣ�1.ָ������ 2.�ϲ�ͬ���� 3.ϵ��Ϊ0�Ľڵ㲻������������ 4.��

            while (cur->next != NULL && cur->next->index > newnode->index)
            {
                //��ѭ�������������ֿ��ܣ�
                //1.cur->next->index < newnode->index 
                //2.cur->next->index == newnode->index
                cur = cur->next;
            }

            if (cur->next == NULL || cur->next->index != newnode->index)
            {
                /*
                ** pre->nextΪNULLʱ, Ԫ��ֵΪ��С, ���������Ϊ��β
                ** ���ж�pre->next�Ƿ�ΪNULL���Է�ֹ������ж������ֶԿ�ָ������õĴ���
                */
                newnode->next = cur->next;
                cur->next = newnode;
            }
            else
            {
                //2.cur->next->index == newnode->index
                cur->next->index += newnode->index;
                free(newnode);
            }
        }
    }
    return new->next;
}

//�������ʽ֮�ͣ�����һ��������
//��Ŀ�����������Ѿ����ս���˳�����кã����ʱ����Ҫ����˳������⣬ͬʱ�ӷ�Ҳ����Ҫ����ͬ����ϲ���
//���ӷ���Ҫ���� ϵ����Ϊ�෴���������Ϊ0�������
Polynomial* PolynomialSum(Polynomial* A, Polynomial* B)
{
    Polynomial* curA = A;
    Polynomial* curB = B;

    /*
    ** ���ÿ���˳�����⣬����ÿ�ζ�������ֱ��ά��һ��βָ�����
    */
    Polynomial* new = NULL;
    Polynomial* tail = new;

    while (curA && curB)
    {
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        newnode->next = NULL;

        if (curA->index == curB->index)
        {
            if (curA->coefficient + curB->coefficient)//ϵ���Ͳ�Ϊ��
            {
                newnode->coefficient = curA->coefficient + curB->coefficient;
                newnode->index = curA->index;
            }
            else //ϵ����Ϊ0
            {
                //���������ӽڵ㣬ֱ�ӿ�ʼ��һ��ѭ��
                free(newnode);
                curA = curA->next;
                curB = curB->next;
                continue;
            }
            curA = curA->next;
            curB = curB->next;
        }
        else if (curA->index > curB->index)
        {
            if (curB->coefficient == 0)
                curB = curB->next;
            
            newnode->coefficient = curA->coefficient;
            newnode->index = curA->index;
            curA = curA->next;
        }
        else //curA->index < curB->index
        {
            if (curA->coefficient == 0)
                curA = curA->next;

            newnode->coefficient = curB->coefficient;
            newnode->index = curB->index;
            curB = curB->next;
        }

        //ִ�����ӽڵ�
        if (new == NULL)
        {
            new = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    //��ѭ����һ��Ϊ�գ�һ����Ϊ��
    if (curA)
    {
        if (tail)
            tail->next = curA;
        else
            new = curA;
    }
    if (curB)
    {
        if (tail)
            tail->next = curB;
        else
            new = curB;
    }
    return new;

}


int main()
{
    //A����ʽ
    Polynomial* A = PolynomialInit();
    
    //B����ʽ
    Polynomial* B = PolynomialInit();
    
    ////����ʽ�˻�
    Polynomial* Product = PolynomialMult(A, B);
    
    ////����ʽ֮��
    Polynomial* sum = PolynomialSum(A, B);
    
    ////��ӡ
    SLPrint(Product);
    printf("\n");
    SLPrint(sum);
    return 0;
}
