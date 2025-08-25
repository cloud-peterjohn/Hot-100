// https://leetcode.com/problems/pascals-triangle/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;
        triangle.push_back(vector<int>{1});
        for (int i = 1; i < numRows; ++i)
        {
            vector<int> row;
            for (int j = 0; j <= i; ++j)
            {
                int left_above = 0, right_above = 0;
                if (j - 1 >= 0)
                    left_above = triangle[i - 1][j - 1];
                if (j < triangle[i - 1].size())
                    right_above = triangle[i - 1][j];
                row.push_back(left_above + right_above);
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};