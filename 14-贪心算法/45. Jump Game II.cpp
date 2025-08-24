// https://leetcode.com/problems/jump-game-ii/

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // 只有一个元素，跳跃0次
        if (nums.size() <= 1)
            return 0;
        // 跳跃次数
        int hop = 0;
        // 当前这一跳可以到达的最远位置
        int curr_reach = 0;
        // 下一跳可以达到的最远位置
        int next_reach = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            next_reach = max(next_reach, i + nums[i]);
            if (curr_reach == i)
            {
                // 再跳一次
                hop++;
                curr_reach = next_reach;
            }
            if (curr_reach >= nums.size() - 1)
            {
                // 到达终点
                break;
            }
        }
        return hop;
    }
};