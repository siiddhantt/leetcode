/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        map<int, int> m;
        vector<bool> ans;
        if (prerequisites.size() == 0)
            return vector<bool>(numCourses, false);
        vector<int> ind(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        queue<int> q;
        vector<unordered_set<int>> req(numCourses);
        for (int i = 0; i < numCourses; i++)
            if (ind[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                ind[it]--;
                if (ind[it] == 0)
                    q.push(it);
                req[it].insert(node);
                for (auto i : req[node])
                    req[it].insert(i);
            }
        }
        for (auto it : queries)
        {
            if (req[it[1]].count(it[0]))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
// @lc code=end
