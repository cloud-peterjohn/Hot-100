// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int num_fresh = 0;
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    num_fresh++;
                }
                else if (grid[i][j] == 2) {
                    // 将初始时就腐烂的橘子的坐标入队
                    q.push(pair<int, int>{i , j});
                }
            }
        }

        // BFS (逐层遍历===逐时间遍历)
        int minutes = 0;
        while (!q.empty() && num_fresh > 0) {
            ++minutes;
            int size = q.size();
            // 遍历当前层所有腐烂橘子
            for (int i = 0; i < size; ++i) {
                pair<int, int> p = q.front();
                q.pop();
                // 将其下一层入队 (上下左右)
                vector<vector<int>> direction{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                for (int j = 0; j < direction.size(); ++j) {
                    int rotten_x = p.first + direction[j][0];
                    int rotten_y = p.second + direction[j][1];
                    // 如果是新鲜橘子，则使其变腐烂
                    if (rotten_x >= 0 && rotten_x < m && rotten_y >= 0 && rotten_y < n) {
                        if (grid[rotten_x][rotten_y] == 1) {
                            num_fresh--;
                            grid[rotten_x][rotten_y] = 2;
                            q.push(pair<int, int>{rotten_x, rotten_y});
                        }
                    }
                }
            }
        }
        if (num_fresh > 0) return -1;
        else return minutes;
    }
};