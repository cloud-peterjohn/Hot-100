// https://leetcode.com/problems/move-zeroes/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // 双指针
        int left = 0, right = 0; // left指向非0元的最右端，right指向当前在遍历的元素
        while (left <= right && right < nums.size())
        {
            // 遇到非0元素，将移动至左侧
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};