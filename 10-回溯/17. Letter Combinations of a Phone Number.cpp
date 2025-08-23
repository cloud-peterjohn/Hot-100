// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
private:
    vector<string> result;
    void backtrack(unordered_map<char, vector<char>> &map, string &digits, int curr_layer, string &track)
    {
        if (track.size() == digits.size())
        {
            if (track != "")
            { // 如果没有按下按钮，则字符组合为空
                this->result.push_back(track);
            }
            return;
        }
        vector<char> buttom = map[digits[curr_layer]];
        for (const auto ch : buttom)
        {
            track.push_back(ch);
            backtrack(map, digits, curr_layer + 1, track);
            track.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, vector<char>> map;
        map['2'] = vector<char>{'a', 'b', 'c'};
        map['3'] = vector<char>{'d', 'e', 'f'};
        map['4'] = vector<char>{'g', 'h', 'i'};
        map['5'] = vector<char>{'j', 'k', 'l'};
        map['6'] = vector<char>{'m', 'n', 'o'};
        map['7'] = vector<char>{'p', 'q', 'r', 's'};
        map['8'] = vector<char>{'t', 'u', 'v'};
        map['9'] = vector<char>{'w', 'x', 'y', 'z'};
        string track;
        backtrack(map, digits, 0, track);
        return this->result;
    }
};