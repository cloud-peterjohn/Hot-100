// https://leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode();
        ListNode *dummy_head = head;
        int num1 = 0, num2 = 0, carry = 0;
        while (l1 && l2)
        {
            num1 = l1->val;
            num2 = l2->val;
            head->next = new ListNode((num1 + num2 + carry) % 10);
            head = head->next;
            carry = (num1 + num2 + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            head->next = new ListNode((l1->val + carry) % 10);
            head = head->next;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        }
        while (l2)
        {
            head->next = new ListNode((l2->val + carry) % 10);
            head = head->next;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        }
        if (carry != 0)
            head->next = new ListNode(carry);
        return dummy_head->next;
    }
};