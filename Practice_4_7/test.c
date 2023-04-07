#define _CRT_SECURE_NO_WARNINGS 1
/*
ţ����
CM11 ����ָ�
��Ŀ����������
����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
��дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
������ַΪ��Ŀ���ӣ�
https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
*/
//�𰸣�
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        //��һ���ڱ�λ�ڵ㣬����β��
        struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;

        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        lessTail->next = NULL;
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterTail->next = NULL;

        //ָ������ǰλ��
        struct ListNode* cur = pHead;
        //��curΪ�գ��˳�ѭ���ָ����
        while (cur)
        {
            if (cur->val < x)
            {
                lessTail->next = cur;
                lessTail = lessTail->next;

            }
            else
            {
                greaterTail->next = cur;
                greaterTail = greaterTail->next;
            }
            cur = cur->next;//����
        }
        //������������
        lessTail->next = greaterHead->next;
        //���ÿվͳɻ�
        greaterTail->next = NULL;
        struct ListNode* newHead = lessHead->next;
        return newHead;
    }
};