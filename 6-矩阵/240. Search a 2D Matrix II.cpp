// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool has_integer = false;
        int idx_i = 0, idx_j = n - 1;
        while (idx_i < m && idx_j >= 0)
        {
            if (matrix[idx_i][idx_j] < target)
            {
                // 比目标值小，则向下增大
                ++idx_i;
            }
            else if (matrix[idx_i][idx_j] > target)
            {
                // 比目标值大，则向左减小
                --idx_j;
            }
            else
            {
                // 找到目标值
                has_integer = true;
                break;
            }
        }
        return has_integer;
    }
};