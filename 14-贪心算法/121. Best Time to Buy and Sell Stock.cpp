// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // dp_table[i][j]表示第i天，j指是否持有股票的情况下，最大收益值
        vector<vector<int>> dp_table(n + 1, vector<int>(2, 0));
        // base case
        dp_table[0][0] = 0;
        dp_table[0][1] = INT_MIN; // 还没开始交易就有股票，不合法
        // DP
        for (int i = 1; i < n + 1; ++i)
        {
            // 第i天不持有股票
            dp_table[i][0] = max(dp_table[i - 1][0], dp_table[i - 1][1] + prices[i - 1]);
            // 第i天持有股票
            // 由于只能买入一次，所以买入前dp_table[i - 1][0] === 0
            dp_table[i][1] = max(dp_table[i - 1][1], 0 - prices[i - 1]);
        }
        return dp_table[n][0];
    }
};