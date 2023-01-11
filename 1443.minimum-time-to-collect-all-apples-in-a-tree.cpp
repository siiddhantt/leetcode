/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start
class Solution
{
public:
    int rec(int i, vector<int> &vis, vector<vector<int>> &adj, vector<bool> &hasApple)
    {
        vis[i] = 1;
        int steps = 0;
        for (auto it : adj[i])
        {
            if (vis[it])
                continue;
            int tmp = rec(it, vis, adj, hasApple);
            if (tmp > 0)
                steps += 2 + tmp;
            else if (hasApple[it])
                steps += 2;
        }
        return steps;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return rec(0, vis, adj, hasApple);
    }
};
// @lc code=end
