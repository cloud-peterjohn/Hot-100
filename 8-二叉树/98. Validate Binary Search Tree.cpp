// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool check(TreeNode *root, long min_val, long max_val)
    {
        if (root == nullptr)
            return true;
        // root->val: (min_val, max_val)
        if (!(root->val > min_val && root->val < max_val))
            return false;
        bool left = check(root->left, min_val, root->val);
        bool right = check(root->right, root->val, max_val);
        return (left && right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return check(root, LONG_MIN, LONG_MAX);
    }
};
