/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 */

// @lc code=start
class Solution
{
public:
    int ans = INT_MIN;
    int rec(int i, vector<int> &parent, string &s, vector<vector<int>> &adj)
    {
        int mx1 = 0, mx2 = 0;
        for (auto it : adj[i])
        {
            int path = rec(it, parent, s, adj);
            if (s[i] == s[it])
                continue;
            if (path > mx1)
            {
                mx2 = mx1;
                mx1 = path;
            }
            else
                mx2 = max(mx2, path);
        }
        ans = max(ans, 1 + mx1 + mx2);
        return 1 + mx1;
    }
    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);
        rec(0, parent, s, adj);
        return ans;
    }
};
// @lc code=end
