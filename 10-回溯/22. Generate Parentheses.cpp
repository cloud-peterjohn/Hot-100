// https://leetcode.com/problems/generate-parentheses/

class Solution
{
private:
    vector<string> parentheses;
    void backtrack(const int n, string &track, int &left, int &right)
    {
        if (track.size() == 2 * n)
        {
            if (left == right)
            {
                this->parentheses.push_back(track);
            }
            return;
        }
        // 共需使用n个左括号，当前使用了left个，还存在未使用的左括号
        if (left < n)
        {
            track.push_back('(');
            ++left;
            backtrack(n, track, left, right);
            --left;
            track.pop_back();
        }
        // 右括号数量小于左括号
        if (right < left)
        {
            track.push_back(')');
            ++right;
            backtrack(n, track, left, right);
            --right;
            track.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        string track;
        int left = 0, right = 0;
        backtrack(n, track, left, right);
        return this->parentheses;
    }
};