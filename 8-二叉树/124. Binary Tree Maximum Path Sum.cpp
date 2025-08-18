// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int max_path_sum = INT_MIN;
    int traverse(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        // 左右子树能实现的最大路径和
        int left_child = traverse(root->left);
        int right_child = traverse(root->right);
        // 如果是负数，则不取
        left_child = max(left_child, 0);
        right_child = max(right_child, 0);

        // 经过当前根结点的最大路径和（不从当前根节点出发）
        int path_sum = left_child + right_child + root->val;
        this->max_path_sum = max(this->max_path_sum, path_sum);

        // 返回当前根结点及其子树能实现的最大路径和
        return max(left_child, right_child) + root->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        traverse(root);
        return this->max_path_sum;
    }
};