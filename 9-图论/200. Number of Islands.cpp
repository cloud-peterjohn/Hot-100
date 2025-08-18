// https://leetcode.com/problems/number-of-islands/

class Solution
{
private:
    void flood_dfs(vector<vector<char>> &grid, int i, int j)
    {
        int row = grid.size(), col = grid[0].size();
        // 越界
        if (i < 0 || i >= row || j < 0 || j >= col)
            return;
        // 如果是陆地，则淹没
        if (grid[i][j] == '1')
        {
            grid[i][j] = '0';
            flood_dfs(grid, i - 1, j);
            flood_dfs(grid, i + 1, j);
            flood_dfs(grid, i, j - 1);
            flood_dfs(grid, i, j + 1);
        }
        // 如果是海洋，则停止遍历
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        int num_islands = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    // 遇见陆地，则计数并淹没这座岛屿
                    ++num_islands;
                    flood_dfs(grid, i, j);
                }
            }
        }
        return num_islands;
    }
};