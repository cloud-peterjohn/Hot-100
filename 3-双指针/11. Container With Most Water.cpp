// https://leetcode.com/problems/container-with-most-water/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // 移动较长的边，容积要么不变要么缩小，移动较短的边，才有可能增大容积
        // 从最宽的容器开始，逐渐向内收缩，每次都移动较短的那条边，就不会错过最大容积
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left <= right)
        {
            int curr_area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, curr_area);
            // 移动较短的边
            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return max_area;
    }
};