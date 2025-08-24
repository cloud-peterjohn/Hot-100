// https://leetcode.com/problems/palindrome-partitioning/

class Solution
{
private:
    vector<vector<string>> partitions;
    vector<vector<bool>> dp_table;
    void palindrome(const string s)
    {
        vector<vector<bool>> dp_tables(s.size(), vector<bool>(s.size(), false));
        // dp_table[i][j]表示s[i:j]是否为回文串
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = i; j < s.size(); ++j)
            {
                // base case
                if (j == i)
                    dp_tables[i][j] = true; // 只有一个字符
                if (j - i == 1 && s[i] == s[j])
                    dp_tables[i][j] = true; // 两个字符
                if (j - i > 1)
                { // 三个字符及以上
                    dp_tables[i][j] = (s[i] == s[j]) && dp_tables[i + 1][j - 1];
                }
            }
        }
        this->dp_table = dp_tables;
    }
    void backtrack(const string s, int start, vector<string> &track)
    {
        if (start == s.size())
        {
            this->partitions.push_back(track);
            return;
        }
        for (int i = start; i < s.size(); ++i)
        {
            // 分割出子串s[start:i]，如果其为回文串，则继续
            if (this->dp_table[start][i])
            {
                // 剩余部分s[i+1:]继续递归
                track.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, track);
                track.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        palindrome(s);
        vector<string> track;
        backtrack(s, 0, track);
        return this->partitions;
    }
};