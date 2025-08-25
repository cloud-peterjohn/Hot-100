// https://leetcode.com/problems/climbing-stairs/

class Solution
{
public:
    int climbStairs(int n)
    {
        // 爬到第i层的方案
        vector<int> dp_table(n + 1);
        dp_table[0] = 1;
        dp_table[1] = 1;
        for (int i = 2; i < n + 1; ++i)
        {
            dp_table[i] = dp_table[i - 1] + dp_table[i - 2]; // 走一步和走两步
        }
        return dp_table[n];
    }
};