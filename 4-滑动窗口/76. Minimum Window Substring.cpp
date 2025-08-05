// https://leetcode.com/problems/minimum-window-substring/

class Solution
{
private:
    bool is_substring(unordered_map<char, int> &str, unordered_map<char, int> &target)
    {
        for (auto &p : target)
        {
            // 允许子串中包含比target更多种类的字符，同一字符也允许出现更多次
            if (str[p.first] < p.second)
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        int min_window_size = 999999, min_window_i = 0, min_window_j = 0;
        int i = 0, j = 0, m = s.size();  // 滑动窗口[i, j)
        unordered_map<char, int> map;    // 记录当前窗口子串的各字符数量
        unordered_map<char, int> target; // 记录目标串t中各字符数量
        for (const auto ch : t)
            target[ch]++;
        while (i < m && j < m)
        {
            // 将j指向的字符加入窗口
            map[s[j]]++;
            j++;
            // 如果包含了所有字符，则缩小窗口
            while (is_substring(map, target))
            {
                // 记录当前的最小窗口长度
                if (j - i < min_window_size)
                {
                    min_window_size = j - i;
                    min_window_i = i;
                }
                // 缩小窗口
                map[s[i]]--;
                i++;
            }
            // 此时，经过缩小，窗口内子串已不符合要求，窗口继续增大
        }
        if (min_window_size == 999999)
            return "";
        else
            return s.substr(min_window_i, min_window_size);
    }
};