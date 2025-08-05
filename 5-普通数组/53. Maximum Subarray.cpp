// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp_table(n + 1, -999999); // dp_table[i]代表以nums[i - 1]结尾的子数组的最大元素和
        // DP
        for (int i = 1; i <= n; ++i)
        {
            dp_table[i] = max(dp_table[i - 1] + nums[i - 1], nums[i - 1]);
        }
        // 返回最大子数组和
        int max_sum = -999999;
        for (const auto sum : dp_table)
            max_sum = max(max_sum, sum);
        return max_sum;
    }
};