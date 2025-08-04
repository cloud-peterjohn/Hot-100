// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // nums有负数，所以无法使用滑动窗口，只能用前缀和
        int n = nums.size();
        // 计算前缀和
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // 寻找子数组
        int subarr_count = 0;
        unordered_map<int, int> map; // 记录每个前缀和出现的次数
        map[0] = 1;                  // 前缀和为0只出现了一次
        for (int i = 0; i < n; ++i)
        {
            // 寻找prefix[i] - prefix[j] == k
            if (map.find(prefix[i + 1] - k) != map.end())
            {
                subarr_count += map[prefix[i + 1] - k];
            }
            map[prefix[i + 1]] += 1; // 出现次数的修改要在最后，避免计数了空子数组
        }
        return subarr_count;
    }
};