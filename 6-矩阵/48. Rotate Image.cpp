// https://leetcode.com/problems/rotate-image

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        // 沿主对角线为轴翻转
        for (int i = 0; i < m; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 每行分别逆序
        for (int i = 0; i < m; ++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};