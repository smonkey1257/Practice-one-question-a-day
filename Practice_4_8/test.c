//���ж�һ�������Ƿ�Ϊ��������
//��Ŀ���ӣ�
https://www.nowcoder.com/questionTerminal/17117937637545e8a78b62957532db91

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  * �ж��Ƿ�Ϊ��������
  * @param head ListNode�� ����ͷ
  * @return bool������
  */

  //�ҵ��м�ڵ�
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


//��ת����
struct ListNode* ReverseList(struct ListNode* head)
{
    //�������ؿ�ָ��
    if (head == NULL)
        return NULL;
    //����Ϊ��+�����һ���ڵ�
    struct ListNode* cur, * next;
    cur = next = head;
    next = next->next;
    cur->next = NULL;
    cur = next;
    //�������ڵ�
    while (cur)
    {
        next = next->next;
        cur->next = head;
        head = cur;
        cur = next;
    }
    //������ͷ�ڵ�
    return head;
}
//�жϻ���
bool isPalindrome(struct ListNode* head) {
    //���м�ڵ�
    struct ListNode* mid = MiddleNode(head);
    //���ú�������
    struct ListNode* rHead = ReverseList(mid);
    //�жϻ���
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