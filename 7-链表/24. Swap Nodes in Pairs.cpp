// https://leetcode.com/problems/swap-nodes-in-pairs/

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
private:
    void swap_list(ListNode *prev, ListNode *curr)
    {
        if (curr == nullptr)
        {
            prev->next = nullptr;
            return;
        }
        if (curr->next == nullptr)
        {
            prev->next = curr;
            return;
        }
        // 交换两个结点
        ListNode *next = curr->next;
        ListNode *next_next = curr->next->next;
        prev->next = next;
        next->next = curr;
        curr->next = next_next;
        // 递归！！！
        swap_list(curr, next_next);
    }

public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy_head = new ListNode();
        swap_list(dummy_head, head);
        return dummy_head->next;
    }
};