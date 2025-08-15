// https://leetcode.com/problems/symmetric-tree/

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
    // 判断left子树和right子树是不是完全对称的结构
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        // 同时为空，对称
        if (left == nullptr && right == nullptr)
            return true;
        // 仅一个为空，不对称
        if (left == nullptr || right == nullptr)
            return false;
        // 当前结点值相同且子树满足对称，则对称
        if (
            (left->val == right->val) &&
            isMirror(left->left, right->right) && // 左树的左子树与右树的右子树相同
            isMirror(left->right, right->left)    // 左树的右子树与右树的左子树相同
        )
            return true;
        // 其他情况，不对称
        return false;
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isMirror(root->left, root->right);
    }
};