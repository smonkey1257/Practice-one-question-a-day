//请判断一个链表是否为回文链表。
//题目链接：
https://www.nowcoder.com/questionTerminal/17117937637545e8a78b62957532db91

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  * 判断是否为回文链表
  * @param head ListNode类 链表头
  * @return bool布尔型
  */

  //找到中间节点
struct ListNode* MiddleNode(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


//翻转链表
struct ListNode* ReverseList(struct ListNode* head)
{
    //空链表返回空指针
    if (head == NULL)
        return NULL;
    //链表不为空+处理第一个节点
    struct ListNode* cur, * next;
    cur = next = head;
    next = next->next;
    cur->next = NULL;
    cur = next;
    //处理后面节点
    while (cur)
    {
        next = next->next;
        cur->next = head;
        head = cur;
        cur = next;
    }
    //返回新头节点
    return head;
}
//判断回文
bool isPalindrome(struct ListNode* head) {
    //找中间节点
    struct ListNode* mid = MiddleNode(head);
    //逆置后半段链表
    struct ListNode* rHead = ReverseList(mid);
    //判断回文
    struct ListNode* curHead = head;
    struct ListNode* curRHead = rHead;
    while (curHead && curRHead)
    {
        if (curHead->val == curRHead->val)
        {
            curHead = curHead->next;
            curRHead = curRHead->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}