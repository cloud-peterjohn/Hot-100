// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
class Solution
{
private:
    vector<int> result;
    void mid_order(TreeNode *root)
    {
        if (root == nullptr)
            return;
        mid_order(root->left);
        result.push_back(root->val);
        mid_order(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        mid_order(root);
        return this->result;
    }
};