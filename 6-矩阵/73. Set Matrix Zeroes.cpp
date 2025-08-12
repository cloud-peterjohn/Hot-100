// https://leetcode.com/problems/set-matrix-zeroes

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        // tag[0][i]标记第i - 1列有无0出现，tag[i][0]标记第i - 1行有无0出现
        vector<vector<bool>> tag(m + 1, vector<bool>(n + 1, false));
        // 遍历数组，记录有无0出现
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    tag[0][j + 1] = true;
                    tag[i + 1][0] = true;
                }
            }
        }
        // 设置为0的行列
        for (int i = 1; i < m + 1; ++i)
        {
            if (tag[i][0])
            {
                // 将i - 1行全部设置为0
                for (int k = 0; k < n; ++k)
                {
                    matrix[i - 1][k] = 0;
                }
            }
        }
        for (int j = 1; j < n + 1; ++j)
        {
            if (tag[0][j])
            {
                // 将j - 1列全部设置为0
                for (int k = 0; k < m; ++k)
                {
                    matrix[k][j - 1] = 0;
                }
            }
        }
    }
};