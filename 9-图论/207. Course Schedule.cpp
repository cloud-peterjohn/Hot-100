// https://leetcode.com/problems/course-schedule/

class Solution
{
private:
    bool is_cycle = false;
    void dfs(const vector<vector<int>> &graph, int node, vector<bool> &visited, vector<bool> &on_path)
    {
        if (on_path[node] == true)
        {
            // 出现了环
            this->is_cycle = true;
            return;
        }
        if (visited[node] == true)
        {
            // 避免重复遍历
            return;
        }
        // 遍历当前结点
        visited[node] = true;
        on_path[node] = true;
        // DFS
        for (int i = 0; i < graph[node].size(); ++i)
        {
            dfs(graph, graph[node][i], visited, on_path);
        }
        on_path[node] = false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 构建邻接图
        vector<vector<int>> graph(numCourses);
        for (const auto prereq : prerequisites)
        {
            graph[prereq[0]].push_back(prereq[1]);
        }
        // DFS判断是否有环
        vector<bool> visited(numCourses, false);
        vector<bool> on_path(numCourses, false);
        for (int node = 0; node < numCourses; ++node)
        { // 避免不连通
            dfs(graph, node, visited, on_path);
            if (this->is_cycle)
                return false;
        }
        return true;
    }
};