// https://leetcode.com/problems/permutations/

class Solution
{
private:
    vector<vector<int>> results;
    void backtrack(const vector<int> &nums, vector<bool> &visited, vector<int> &track)
    {
        if (track.size() == nums.size())
        {
            this->results.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, visited, track);
            track.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> visited(nums.size(), false);
        vector<int> track;
        backtrack(nums, visited, track);
        return this->results;
    }
};