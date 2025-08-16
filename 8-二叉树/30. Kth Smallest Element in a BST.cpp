// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kth_smallest = INT_MIN;
    int traverse_k = 0;
    void traverse(TreeNode *root, const int k)
    {
        if (root == nullptr)
            return;
        traverse(root->left, k);
        // 中序位置
        ++traverse_k;
        if (traverse_k == k)
        {
            // 遍历到第k个数
            kth_smallest = root->val;
            return;
        }
        traverse(root->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        // BST的中序遍历即为有序递增序列
        traverse(root, k);
        return this->kth_smallest;
    }
};