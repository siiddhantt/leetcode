/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adj(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(source);
        while (!q.empty())
        {
            int node = q.front();
            if (node == destination)
                return true;
            q.pop();
            vis[node] = 1;
            for (auto it : adj[node])
            {
                if (vis[it] != 1)
                    q.push(it);
            }
        }
        return false;
    }
};
// @lc code=end
