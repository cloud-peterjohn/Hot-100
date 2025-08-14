// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 检查结点数量是否还有K个
        int count = 0;
        ListNode *head_count = head;
        while (head_count)
        {
            count++;
            head_count = head_count->next;
        }
        if (count < k)
        {
            return head; // 保持原状
        }

        // 翻转前K个结点
        ListNode *prev_node = nullptr;
        ListNode *curr_node = head;
        ListNode *next_node = head->next;
        for (int i = 0; i < k; ++i)
        {
            // 翻转
            curr_node->next = prev_node;
            // 更新结点
            prev_node = curr_node;
            curr_node = next_node;
            if (next_node)
                next_node = next_node->next;
        }

        // 递归处理剩余结点，并连接起来
        head->next = reverseKGroup(curr_node, k);
        return prev_node;
    }
};