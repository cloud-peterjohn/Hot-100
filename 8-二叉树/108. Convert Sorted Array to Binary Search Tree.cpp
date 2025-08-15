// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode *buildTree(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        if (left == right)
        {
            TreeNode *root_node = new TreeNode(nums[left]);
            return root_node;
        }
        // 递归
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        TreeNode *left_child = buildTree(nums, left, mid - 1);
        TreeNode *right_child = buildTree(nums, mid + 1, right);
        // 连接
        root->left = left_child;
        root->right = right_child;
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildTree(nums, 0, nums.size() - 1);
    }
};