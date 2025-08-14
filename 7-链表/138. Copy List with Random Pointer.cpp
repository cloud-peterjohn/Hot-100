// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        unordered_map<Node *, Node *> map; // 记录旧结点到新节点的索引

        // 记录头节点
        Node *old_head = head;
        Node *new_head = new Node(old_head->val);
        Node *new_head_dummy = new_head;
        // 复制链式表
        map[old_head] = new_head;
        old_head = old_head->next;
        while (old_head)
        {
            new_head->next = new Node(old_head->val);
            new_head = new_head->next;
            map[old_head] = new_head;
            old_head = old_head->next;
        }

        // 复制随机指针
        Node *old_head1 = head;
        Node *new_head1 = new_head_dummy;
        while (old_head1)
        {
            new_head1->random = map[old_head1->random];
            old_head1 = old_head1->next;
            new_head1 = new_head1->next;
        }
        return new_head_dummy;
    }
};