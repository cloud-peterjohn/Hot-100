// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // 查找费时，因此转为哈希集合实现O(1)的查找
        unordered_set<int> set(nums.begin(), nums.end());
        // 对于每个数字计算以其为开头的最长连续序列
        int max_length = 0;
        for (auto num : set)
        { // 遍历set而不是nums，因为可能有很多重复值
            // 只从连续序列的起点开始查找(即不存在num - 1)，避免在子序列上浪费时间
            if (set.find(num - 1) != set.end())
                continue;
            int curr_length = 1;
            int curr_num = num;
            while (set.find(curr_num + 1) != set.end())
            {
                // 如果存在递增数字
                curr_num++;
                curr_length++;
            }
            max_length = max(curr_length, max_length);
        }
        return max_length;
    }
};
