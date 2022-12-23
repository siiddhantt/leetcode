/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
class Solution
{
public:
    void dfs1(int i, int prev, vector<int> &cou, vector<int> &ans, vector<vector<int>> &adj)
    {
        for (auto it : adj[i])
            if (it != prev)
            {
                dfs1(it, i, cou, ans, adj);
                cou[i] += cou[it];
                ans[i] += ans[it] + cou[it];
            }
    }
    void dfs2(int i, int prev, vector<int> &cou, vector<int> &ans, vector<vector<int>> &adj)
    {
        for (auto it : adj[i])
            if (it != prev)
            {
                ans[it] = ans[i] + ans.size() - 2 * cou[it];
                dfs2(it, i, cou, ans, adj);
            }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<int> cou(n, 1), ans(n, 0);
        vector<vector<int>> adj(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs1(0, -1, cou, ans, adj);
        dfs2(0, -1, cou, ans, adj);
        return ans;
    }
};
// @lc code=end
