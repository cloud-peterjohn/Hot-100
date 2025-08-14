// https://leetcode.com/problems/sort-list/

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
    ListNode *sortList(ListNode *head)
    {
        // base case
        if (!head || !head->next)
            return head;

        // 找到中点的前驱节点
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 从中点断为两半
        ListNode *l1_head = head;
        ListNode *l2_head = slow->next;
        slow->next = nullptr;

        // 归并排序
        ListNode *l1 = sortList(l1_head);
        ListNode *l2 = sortList(l2_head);
        // 合并两个有序链表
        ListNode *l_new = new ListNode();
        ListNode *l_dummy = l_new;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                l_new->next = l1;
                l_new = l_new->next;
                l1 = l1->next;
            }
            else
            {
                l_new->next = l2;
                l_new = l_new->next;
                l2 = l2->next;
            }
        }
        if (l1)
            l_new->next = l1;
        if (l2)
            l_new->next = l2;
        return l_dummy->next;
    }
};