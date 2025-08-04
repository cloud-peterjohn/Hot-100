// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int m = s.size(), n = p.size();
        if (m < n)
            return vector<int>{};
        vector<int> result;
        // 记录目标串中各字符个数
        unordered_map<char, int> target;
        for (int i = 0; i < n; ++i)
        {
            target[p[i]]++;
        }
        // 记录窗口内字符个数
        unordered_map<char, int> map;
        // 初始化固定大小的滑动窗口
        int left = 0;
        for (int i = left; i < n; ++i)
        {
            map[s[i]]++;
        }
        // 滑动窗口
        while (left + n - 1 <= m - 1)
        {
            // 判断异味词
            bool is_anagram = true;
            for (const auto &p : map)
            {
                if (target[p.first] != p.second)
                {
                    is_anagram = false;
                    break;
                }
            }
            if (is_anagram)
                result.push_back(left);
            // 窗口右移
            if (left + n < m)
            {
                map[s[left]]--;
                map[s[left + n]]++;
            }
            left++;
        }
        return result;
    }
};