// https://leetcode.com/problems/trapping-rain-water/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        // 记录每个位置左边和右边的最大高度
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        // 从左向右计算每个位置左边的最大高度(DP思想)
        for (int i = 1; i < n; ++i)
        {
            left[i] = max(left[i - 1], height[i - 1]);
        }
        // 从右向左计算每个位置右边的最大高度(DP思想)
        for (int i = n - 2; i >= 0; --i)
        {
            right[i] = max(right[i + 1], height[i + 1]);
        }
        // 对于每个位置，根据左右最大高度，计算其正上方能积的水量
        int water = 0;
        for (int i = 0; i < n; ++i)
        {
            int water_i = min(left[i], right[i]) - height[i];
            if (water_i < 0)
                water_i = 0;
            water += water_i;
        }
        return water;
    }
};