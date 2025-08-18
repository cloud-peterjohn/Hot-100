// https://leetcode.com/problems/path-sum-iii/

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
    // 记录从根节点到当前节点的路径和及其对应的出现次数
    unordered_map<long long, int> map;
    // 从根节点到当前节点的路径和
    long long path_sum = 0;
    // 二叉树中路径和等于targetSum的路径数目
    int target_path_cnt = 0;

    void traverse(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return;
        // 从根节点到当前节点的路径和
        this->path_sum = this->path_sum + root->val;
        // 如果存在和为targetSum的子路径
        if (this->map.find(this->path_sum - targetSum) != this->map.end())
        {
            this->target_path_cnt += map[this->path_sum - targetSum];
        }
        // 更新map
        ++map[this->path_sum];

        traverse(root->left, targetSum);
        traverse(root->right, targetSum);

        // 回溯
        --map[this->path_sum];
        this->path_sum = this->path_sum - root->val;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        this->map[0] = 1;
        traverse(root, targetSum);
        return this->target_path_cnt;
    }
};