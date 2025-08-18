// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode *build(const vector<int> &preorder, int pre_begin, int pre_end, const vector<int> &midorder, int mid_begin, int mid_end)
    {
        if (pre_begin > pre_end || mid_begin > mid_end)
            return nullptr;
        // 先序遍历首个元素为根节点
        int root_val = preorder[pre_begin];
        TreeNode *root = new TreeNode(root_val);
        // 找到根节点对应中序遍历的位置
        int root_idx_mid = -1;
        for (int i = mid_begin; i <= mid_end; ++i)
        {
            if (midorder[i] == root_val)
            {
                root_idx_mid = i;
            }
        }
        // 先序序列左子树：[pre_begin + 1, pre_begin + (root_idx_mid - mid_begin)]
        // 中序序列左子树：[mid_begin, root_idx_mid - 1]
        TreeNode *left_child = build(
            preorder, pre_begin + 1, pre_begin + (root_idx_mid - mid_begin),
            midorder, mid_begin, root_idx_mid - 1);
        // 先序序列右子树：[pre_begin + (root_idx_mid - mid_begin) + 1, pre_end]
        // 中序序列右子树：[root_idx_mid + 1, mid_end]
        TreeNode *right_child = build(
            preorder, pre_begin + (root_idx_mid - mid_begin) + 1, pre_end,
            midorder, root_idx_mid + 1, mid_end);
        root->left = left_child;
        root->right = right_child;
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(
            preorder, 0, preorder.size() - 1,
            inorder, 0, inorder.size() - 1);
    }
};