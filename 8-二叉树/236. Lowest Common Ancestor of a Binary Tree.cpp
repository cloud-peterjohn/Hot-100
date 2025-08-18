// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 二叉树中的最近公共祖先（LCA）问题：递归解法
        if (root == nullptr || root == p || root == q)
        {
            // 如果为空，或者找到了目标结点，则返回
            return root;
        }

        // 如果子树中无目标p/q结点，则返回nullptr，否则返回p/q
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 如果左子树返回p，右子树返回q，则root为最近公共祖先
        if (left != nullptr && right != nullptr)
            return root;
        // 单边找到目标节点则向上传递
        if (right != nullptr)
            return right;
        if (left != nullptr)
            return left;
        // 两边都没找到，返回nullptr
        return nullptr;
    }
};
