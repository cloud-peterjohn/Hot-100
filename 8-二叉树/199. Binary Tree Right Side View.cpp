// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> right_view;

public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
            return vector<int>{};
        // 层序遍历
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int q_size = q.size();
            // 遍历该层
            for (int i = 0; i < q_size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (i == q_size - 1)
                {
                    // 本层最右边的结点
                    this->right_view.push_back(node->val);
                }
                // 左右子节点入队
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return this->right_view;
    }
};