// https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class State
{
public:
    TreeNode *node;
    int depth;
    State() : node(nullptr), depth(0) {}
    State(TreeNode *node, int depth) : node(node), depth(depth) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return vector<vector<int>>{};

        int max_depth = 0;
        unordered_map<int, vector<int>> map; // 记录每层对应的结点列表
        queue<State> q;
        q.push(State(root, 0));
        while (!q.empty())
        {
            State s = q.front();
            q.pop();
            max_depth = max(max_depth, s.depth);
            map[s.depth].push_back(s.node->val);
            if (s.node->left)
                q.push(State(s.node->left, s.depth + 1));
            if (s.node->right)
                q.push(State(s.node->right, s.depth + 1));
        }

        vector<vector<int>> result;
        for (int i = 0; i <= max_depth; ++i)
        {
            result.push_back(map[i]);
        }
        return result;
    }
};