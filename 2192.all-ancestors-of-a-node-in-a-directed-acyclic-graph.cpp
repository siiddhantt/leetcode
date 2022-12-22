/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<int> ind(n, 0);
        vector<vector<int>> adj(n), ans;
        vector<set<int>> anc(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (ind[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (--ind[it] == 0)
                    q.push(it);
                anc[it].insert(node);
                for (auto i : anc[node])
                    anc[it].insert(i);
            }
        }
        for (auto it : anc)
        {
            vector<int> tmp(it.begin(), it.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end
