// https://leetcode.com/problems/sliding-window-maximum/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> result;
        deque<int> dq; // 记录窗口内元素的下标，dq内索引是递增的
        for (int i = 0; i < n; ++i)
        { // i指向窗口最右侧
            // 移除队首小于窗口范围的下标
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            // 移除小于当前值的元素索引，从队尾方向移出，使得保持dq内元素递减
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            // 将当前元素索引i加入队列，nums[i]一定是最小的
            dq.push_back(i);
            // 此时dq内索引是递增的，索引对应的元素是递减的（因为不递减的元素都已经被移出了）
            // 因此，队首就是窗口内最大元素
            if (i >= k - 1)
            {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};