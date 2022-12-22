/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ind(numCourses, 0), vec;
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (ind[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            vec.push_back(node);
            for (auto it : adj[node])
            {
                ind[it]--;
                if (ind[it] == 0)
                    q.push(it);
            }
        }
        return vec.size() == numCourses;
    }
};
// @lc code=end
