// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int max_diameter = 0;
    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        int diameter = left_depth + right_depth;
        max_diameter = max(max_diameter, diameter);
        return max(left_depth, right_depth) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        depth(root);
        return this->max_diameter;
    }
};