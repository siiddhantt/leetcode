/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> adj(n + 1);
        for (auto it : dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        unordered_set<int> g1, g2;
        for (int i = 1; i <= n; i++)
        {
            if (!g1.count(i) && !g2.count(i))
            {
                q.push(i);
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for (auto it : adj[node])
                    {
                        if (g1.count(it) || g2.count(it))
                        {
                            if (g1.count(it))
                                if (g1.count(node))
                                    return false;
                            if (g2.count(it))
                                if (g2.count(node))
                                    return false;
                        }
                        else
                        {
                            q.push(it);
                            if (g1.count(node))
                                g2.insert(it);
                            else
                                g1.insert(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
