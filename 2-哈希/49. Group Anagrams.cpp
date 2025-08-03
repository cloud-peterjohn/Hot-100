// https://leetcode.com/problems/group-anagrams/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> seq_to_strs; // 序列-->对应的字符串
        for (const auto &word : strs)
        {                                 // 每个字母出现的次数相同的两个词是异位词
            unordered_map<char, int> map; // 统计每个字符出现次数
            for (const auto ch : word)
            {
                map[ch]++;
            }
            // 将map序列化，以便快速比较（map1 == map2后台效率低）
            string seq = "00000000000000000000000000";
            for (const auto &p : map)
            {
                seq[p.first - 'a'] = p.second; // 第0位为a的个数，第1为位为b的个数，...
            }
            seq_to_strs[seq].push_back(word);
        }

        vector<vector<string>> result;
        for (const auto &p : seq_to_strs)
        {
            result.push_back(p.second);
        }
        return result;
    }
};