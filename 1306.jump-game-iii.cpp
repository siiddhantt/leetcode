/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (vis[it] == -1)
            {
                dfs(it, adj, vis);
            }
        }
    }
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++)
        {
            int l = i - arr[i];
            int r = i + arr[i];
            if (l >= 0 && l < n)
            {
                adj[i].push_back(l);
            }
            if (r >= 0 && r < n)
            {
                adj[i].push_back(r);
            }
        }
        dfs(start, adj, vis);
        bool res = false;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp = adj[i];
            if (tmp.size() == 2)
            {
                if (tmp[0] == tmp[1] && vis[i] != -1)
                {
                    res = true;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
