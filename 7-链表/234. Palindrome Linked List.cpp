// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
            return true;
        if (head->next == nullptr)
            return true;

        // 找到链表中点
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != nullptr)
        {
            // 奇数个结点，指向右半部分的第一个结点
            slow = slow->next;
        }

        // 翻转链表后半部分
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        ListNode *next = slow->next;
        while (curr != nullptr)
        {
            // 翻转
            curr->next = prev;
            // 更新当前结点
            prev = curr;
            curr = next;
            if (next != nullptr)
                next = next->next;
        }

        // 左序列从head开始，右序列从prev开始，如果左右序列相同，则为回文链表
        ListNode *left = head;
        ListNode *right = prev;
        while (right != nullptr)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};