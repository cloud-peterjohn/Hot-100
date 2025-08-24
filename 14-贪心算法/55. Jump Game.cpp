// https://leetcode.com/problems/jump-game/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_steps = 0;
        for (int i = 0; i <= max_steps && i < nums.size(); ++i)
        {
            // 最远可达距离
            max_steps = max(max_steps, i + nums[i]);
        }
        if (nums.size() - 1 <= max_steps)
            return true; // 可以到达最后面
        else
            return false;
    }
};