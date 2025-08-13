// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 链表A遍历完之后，遍历链表B；链表B遍历完之后，遍历链表A
        // 一定会在相交点相遇（若不相交，则在nullptr相遇）
        ListNode *A = headA;
        ListNode *B = headB;
        while (A != B)
        {
            if (A == nullptr)
                A = headB;
            else
                A = A->next;
            if (B == nullptr)
                B = headA;
            else
                B = B->next;
            // 如果链表不相交，则各自走完A+B之后，都会变为nullptr
        }
        return A;
    }
};