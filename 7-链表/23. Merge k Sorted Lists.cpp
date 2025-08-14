// https://leetcode.com/problems/merge-k-sorted-lists/

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
    struct Compare
    {
        bool operator()(ListNode *l1, ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
        // 初始化优先队列
        for (auto &l : lists)
        {
            if (l)
            {
                pq.push(l);
                l = l->next;
            }
        }
        // 归并
        ListNode *head = new ListNode();
        ListNode *head_dummy = head;
        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            head->next = node;
            head = head->next;
            if (node->next)
                pq.push(node->next);
        }
        return head_dummy->next;
    }
};