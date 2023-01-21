/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
class Solution
{
public:
    vector<int> ans;
    vector<int> rec(int i, vector<int> &vis, vector<vector<int>> &adj, string &labels)
    {
        vector<int> vec(26, 0);
        vector<int> count(26, 0);
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                vec = rec(it, vis, adj, labels);
                for (int j = 0; j < 26; j++)
                    count[j] += vec[j];
            }
        }
        ans[i] = ++count[labels[i] - 'a'];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        ans.resize(n, 0);
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        rec(0, vis, adj, labels);
        return ans;
    }
};
// @lc code=end
