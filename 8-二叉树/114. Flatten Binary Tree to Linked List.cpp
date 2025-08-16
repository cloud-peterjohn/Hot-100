// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
public:
    void flatten(TreeNode *root)
    {
        while (root)
        {
            if (root->left == nullptr)
            {
                root = root->right;
                continue;
            }
            // 找到左子树的最右结点（先序遍历左子树的最后一个结点）
            TreeNode *left_subtree = root->left;
            while (left_subtree->right)
            {
                left_subtree = left_subtree->right;
            }
            TreeNode *right_subtree = root->right;
            // 将右子树接到左子树最右结点的后面（使得右子树最后遍历到）
            left_subtree->right = right_subtree;
            // 将原左子树移动为右子树
            root->right = root->left;
            root->left = nullptr;
            // 当前root已无左子树，root往右下移动继续处理
            root = root->right;
        }
    }
};