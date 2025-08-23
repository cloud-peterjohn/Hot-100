// https://leetcode.com/problems/subsets/

class Solution
{
private:
    vector<vector<int>> subset;
    void backtrack(const vector<int> &nums, int start, vector<int> &track)
    {
        this->subset.push_back(track);
        if (track.size() == nums.size())
            return;
        for (int i = start; i < nums.size(); ++i)
        {
            track.push_back(nums[i]);
            backtrack(nums, i + 1, track);
            track.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> track;
        backtrack(nums, 0, track);
        return this->subset;
    }
};