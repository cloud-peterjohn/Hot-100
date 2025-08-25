// https://leetcode.com/problems/partition-labels/

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> partition;
        // 记录每个字符最后出现的位置
        vector<int> last_pos(26, -1);
        for (int i = 0; i < s.size(); ++i)
        {
            last_pos[s[i] - 'a'] = i;
        }
        // 分割，使得各个字符只出现在同一个片段
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            end = max(end, last_pos[s[i] - 'a']);
            if (i == end)
            {
                // 当前片段内的各个字符均只出现在该片段内
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};