// https://leetcode.com/problems/product-of-array-except-self/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        // 前缀积
        vector<int> prefix(n + 1, 1);
        for (int i = 1; i < n + 1; ++i)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        // 后缀积
        vector<int> suffix(n + 1, 1);
        for (int i = n - 1; i >= 0; --i)
        {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        // Product of Array Except Self
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i)
        {
            result[i] = prefix[i] * suffix[i + 1];
        }
        return result;
    }
};