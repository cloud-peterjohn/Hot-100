// https://leetcode.com/problems/combination-sum/

class Solution
{
private:
    vector<vector<int>> combinations;
    void backtrack(const vector<int> &candidates, const int target, int start, vector<int> &track, int &track_sum)
    {
        if (track_sum >= target)
        {
            if (track_sum == target)
            {
                this->combinations.push_back(track);
            }
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            track_sum += candidates[i];
            track.push_back(candidates[i]);
            // 允许重复，所以start=i而不是i+1
            backtrack(candidates, target, i, track, track_sum);
            track_sum -= candidates[i];
            track.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> track;
        int track_sum = 0;
        backtrack(candidates, target, 0, track, track_sum);
        return this->combinations;
    }
};