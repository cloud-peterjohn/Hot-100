// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = head->next;
        while (curr)
        {
            // 逆序连接
            curr->next = prev;
            // 更新下一个结点
            prev = curr;
            curr = next;
            if (next)
                next = next->next;
        }
        return prev;
    }
};