/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, vector<vector<int>> &graph, vector<int> &vis, vector<int> &issafe)
    {
        vis[i] = 1;
        for (auto it : graph[i])
        {
            if (issafe[it] == 1)
            {
                issafe[i] = 1;
                continue;
            }
            if (vis[it] == -1)
            {
                dfs(it, graph, vis, issafe);
                if (issafe[it] < 0)
                {
                    issafe[i] = -1;
                    return;
                }
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, -1), issafe(n, -1), res;
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 0)
            {
                issafe[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                dfs(i, graph, vis, issafe);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (issafe[i] > 0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
