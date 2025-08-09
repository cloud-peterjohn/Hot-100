// https://leetcode.com/problems/rotate-array/

class Solution
{
public:
    void print(vector<int> &nums)
    {
        for (auto n : nums)
            cout << n << " ";
        cout << endl;
    }
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // 避免越界访问
        // reverse(first, last)是反转左闭右开区间[first, last)
        // 反转前n-k个
        reverse(nums.begin(), nums.begin() + n - k);
        // 反转后k个
        reverse(nums.begin() + n - k, nums.end());
        // 全部反转
        reverse(nums.begin(), nums.end());
    }
};