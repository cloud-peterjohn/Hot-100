// https://leetcode.com/problems/spiral-matrix

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        // 维护四个边界
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (left <= right && top <= bottom)
        {
            if (top <= bottom)
            {
                // 从左至右
                for (int i = left; i <= right; ++i)
                {
                    result.push_back(matrix[top][i]);
                }
                ++top;
            }
            if (left <= right)
            {
                // 从上至下
                for (int i = top; i <= bottom; ++i)
                {
                    result.push_back(matrix[i][right]);
                }
                --right;
            }
            if (top <= bottom)
            {
                // 从右至左
                for (int i = right; i >= left; --i)
                {
                    result.push_back(matrix[bottom][i]);
                }
                --bottom;
            }
            if (left <= right)
            {
                // 从下至上
                for (int i = bottom; i >= top; --i)
                {
                    result.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return result;
    }
};