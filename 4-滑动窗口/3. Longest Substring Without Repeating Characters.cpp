// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
private:
    bool is_dulplicate(const unordered_map<char, int> &map)
    {
        bool is_dup = false;
        for (const auto &p : map)
        {
            if (p.second > 1)
            {
                is_dup = true;
                break;
            }
        }
        return is_dup;
    }

public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int max_length = 0;
        // 滑动窗口[left, right)
        int left = 0, right = 0;
        // 记录窗口内各字符数量
        unordered_map<char, int> map;
        while (left <= right && right < n)
        {
            // 将right指向的字符加入窗口
            map[s[right]]++;
            right++;
            // 如果包含重复字符，则缩小窗口
            bool is_dup = is_dulplicate(map);
            while (is_dup)
            {
                map[s[left]]--;
                left++;
                // 再次判断是否包含重复字符
                is_dup = is_dulplicate(map);
            }
            // 记录无重复字符的字串长度
            max_length = max(max_length, right - left);
        }
        return max_length;
    }
};