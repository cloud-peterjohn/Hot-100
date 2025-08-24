// https://leetcode.com/problems/n-queens/

class Solution
{
private:
    vector<vector<string>> results;
    vector<string> convert_string(const vector<vector<bool>> &queens)
    {
        int m = queens.size(), n = queens[0].size();
        vector<string> board;
        for (int i = 0; i < m; ++i)
        {
            string board_row;
            for (int j = 0; j < n; ++j)
            {
                if (queens[i][j])
                    board_row.push_back('Q');
                else
                    board_row.push_back('.');
            }
            board.push_back(board_row);
        }
        return board;
    }
    void backtrack(const int n, int curr_row, vector<vector<bool>> &queens, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2)
    {
        // 每次递归在一行中放置queen，已经处理完所有行
        if (curr_row == n)
        {
            this->results.push_back(convert_string(queens));
            return;
        }
        // 遍历每行中的每个可放置位置（每列）
        for (int curr_col = 0; curr_col < n; ++curr_col)
        {
            // 检验该位置是否与其他queen冲突
            if (col[curr_col] || diag1[curr_row + curr_col] || diag2[curr_row + n - 1 - curr_col])
                continue;
            // 回溯，找到剩余行的放置方案
            queens[curr_row][curr_col] = true;
            col[curr_col] = true;
            diag1[curr_row + curr_col] = true;
            diag2[curr_row + n - 1 - curr_col] = true;
            backtrack(n, curr_row + 1, queens, col, diag1, diag2);
            queens[curr_row][curr_col] = false;
            col[curr_col] = false;
            diag1[curr_row + curr_col] = false;
            diag2[curr_row + n - 1 - curr_col] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        // 记录queen的位置
        vector<vector<bool>> queens(n, vector<bool>(n, false));
        // 记录每列是否有queen
        vector<bool> col(n, false);
        // 记录每个主对角沿线是否有queen（row + col, max: 2n-2）
        vector<bool> diag1(2 * n - 1, false);
        // 记录每个次对角沿线是否有queen（row + n-1 - col, max: 2n-2）
        vector<bool> diag2(2 * n - 1, false);
        // 每行、每列、每主对角、每次对角，均只能有一个queen
        backtrack(n, 0, queens, col, diag1, diag2);
        return this->results;
    }
};