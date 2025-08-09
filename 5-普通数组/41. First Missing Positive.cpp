// https://leetcode.com/problems/first-missing-positive/

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // 缺失的数只可能是[1, n + 1]
        int n = nums.size();
        // 把每个在[1,n]范围内的数x放到索引x-1的位置
        for (int i = 0; i < n; ++i)
        {
            // 如果不在正确位置（i+1索引为nums[i]）
            while ((nums[i] >= 1 && nums[i] <= n) && (nums[i] != nums[nums[i] - 1]))
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // 找出第一个不在正确位置上的数
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};