// https://leetcode.com/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map; // 记录nums中每个元素对应的index
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map.find(target - nums[i]) != map.end())
            { // i一定还不在哈希表中，所以不会选择重复的元素
                return vector<int>{i, map[target - nums[i]]};
            }
            else
            {
                map[nums[i]] = i; // 将当前数字和下标放入哈希表
            }
        }
        return vector<int>{-1, -1};
    }
};