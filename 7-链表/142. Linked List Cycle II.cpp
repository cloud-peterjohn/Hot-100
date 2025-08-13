// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return nullptr;
        // 快慢指针均从head出发，第一次相遇
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break; // 需要先移动再判断（初始时fast===slow）
        }
        // 判断是否有环
        if (fast != slow)
            return nullptr;

        // 一指针从head出发，另一指针从相遇点出发，同样的速度，相遇点即为环起点
        ListNode *p1 = head;
        ListNode *p2 = fast;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};