/*
 * @lc app=leetcode id=2368 lang=cpp
 *
 * [2368] Reachable Nodes With Restrictions
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> re;
    int rec(int i, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[i] = 1;
        if (re[i] > 0)
            return 0;
        int num = 1;
        for (auto it : adj[i])
        {
            if (vis[it])
                continue;
            num += rec(it, vis, adj);
        }
        return num;
    }
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (auto it : restricted)
            re[it]++;
        return rec(0, vis, adj);
    }
};
// @lc code=end
