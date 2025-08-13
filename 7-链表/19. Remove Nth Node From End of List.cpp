// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 找到倒数第n个结点的前一个结点（快慢指针）
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        // 如果待删除的是首个结点
        if (fast == nullptr)
        {
            return head->next;
        }
        // 如果是中间节点，则定位至其前驱节点
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除第n个结点
        ListNode *to_be_deleted = slow->next;
        slow->next = slow->next->next;
        delete to_be_deleted;
        return head;
    }
};