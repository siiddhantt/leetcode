/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[i] = 1;
        if (adj[i].size() == 0)
        {
            return;
        }
        for (auto it : adj[i])
        {
            if (vis[it] == -1)
            {
                dfs(it, adj, vis);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int l = connections.size(), cou = 0;
        if (l < (n - 1))
        {
            return -1;
        }
        vector<vector<int>> adj(n);
        vector<int> vis(n, -1);
        for (int i = 0; i < l; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                cou++;
                dfs(i, adj, vis);
            }
        }
        return cou - 1;
    }
};
// @lc code=end
