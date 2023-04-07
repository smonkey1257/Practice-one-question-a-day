#define _CRT_SECURE_NO_WARNINGS 1
/*
牛客网
CM11 链表分割
题目描述描述：
现有一链表的头指针 ListNode* pHead，给一定值x，
编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
以下网址为题目链接：
https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
*/
//答案：
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        //开一个哨兵位节点，方便尾插
        struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;

        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        lessTail->next = NULL;
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterTail->next = NULL;

        //指向链表当前位置
        struct ListNode* cur = pHead;
        //当cur为空，退出循环分割结束
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
            cur = cur->next;//迭代
        }
        //链接两个链表
        lessTail->next = greaterHead->next;
        //不置空就成环
        greaterTail->next = NULL;
        struct ListNode* newHead = lessHead->next;
        return newHead;
    }
};