// https://leetcode.com/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        // 排序
        sort(nums.begin(), nums.end(), less<int>());
        // 遍历第一个数
        int i = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            // 对第二、第三个数进行双指针，规定i<j<k以确保i/j/k互不相同
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    // 不能只简单的++j，因为要跳过所有重复nums[j]和nums[k]值（索引不同值相同），以避免result中重复的元组
                    while (j < k && j + 1 < nums.size() && nums[j] == nums[j + 1])
                    {
                        ++j;
                    }
                    while (j < k && k - 1 >= 0 && nums[k] == nums[k - 1])
                    {
                        --k;
                    }
                    ++j;
                    --k;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    ++j;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    --k;
                }
            }
            // 跳过重复的nums[i]值
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return result;
    }
};