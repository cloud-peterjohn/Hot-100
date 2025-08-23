// https://leetcode.com/problems/word-search/

class Solution
{
private:
    bool is_find = false;
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void backtrack(const vector<vector<char>> &board, const string &word, vector<vector<bool>> &visited, int row, int col, string &track)
    {
        if (this->is_find)
            return;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return;
        if (visited[row][col])
            return;
        if (board[row][col] != word[track.size()])
            return;
        // 已经找到，则不必继续
        if (this->is_find)
            return;
        // 越界
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return;
        // 重复访问
        if (visited[row][col] == true)
            return;
        // 访问该结点
        visited[row][col] = true;
        track.push_back(board[row][col]);
        // 找到word
        if (track == word)
        {
            this->is_find = true;
            return;
        }
        if (track.size() >= word.size())
        {
            // 回溯，取消标记
            visited[row][col] = false;
            track.pop_back();
            return;
        }
        // DFS
        for (const auto dir : direction)
        {
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            backtrack(board, word, visited, new_row, new_col, track);
        }
        // 回溯，取消标记
        visited[row][col] = false;
        track.pop_back();
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.size() == 0)
            return true;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        string track;
        // 寻找起始点
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    backtrack(board, word, visited, i, j, track);
                    if (this->is_find)
                        return true;
                }
            }
        }
        return false;
    }
};