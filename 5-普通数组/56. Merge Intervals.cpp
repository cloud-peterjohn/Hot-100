// https://leetcode.com/problems/merge-intervals/

class Solution
{
private:
    struct Compare
    {
        bool operator()(const vector<int> &v1, const vector<int> &v2)
        {
            // 比较器不能使用<= >=，只能使用严格排序< >
            if (v1[0] == v2[0])
                return v1[1] < v2[1];
            else
                return v1[0] < v2[0];
        }
    };

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 按照start时间排序
        sort(intervals.begin(), intervals.end(), Compare());
        // 合并区间
        int start_time = -1, end_time = -1;
        vector<vector<int>> result;
        for (const auto inter : intervals)
        {
            int start_i = inter[0], end_i = inter[1];
            // 第一个时间区间
            if (start_time == -1 && end_time == -1)
            {
                start_time = start_i;
                end_time = end_i;
                continue;
            }
            if (start_i > end_time)
            {
                // 当前区间与上个时间段无重叠，将上一时间段区间保存
                result.push_back(vector<int>{start_time, end_time});
                // 重新初始化为当前区间
                start_time = start_i;
                end_time = end_i;
            }
            else
            {
                // 当前区间与上个时间段有重叠
                // 可能是子区间则不变，也可能需要延长区间
                end_time = max(end_i, end_time);
            }
        }
        result.push_back(vector<int>{start_time, end_time});
        return result;
    }
};