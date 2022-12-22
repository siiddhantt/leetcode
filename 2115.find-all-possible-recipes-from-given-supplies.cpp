/*
 * @lc app=leetcode id=2115 lang=cpp
 *
 * [2115] Find All Possible Recipes from Given Supplies
 */

// @lc code=start
class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        int n = recipes.size();
        vector<string> ans;
        unordered_map<string, int> rec;
        unordered_set<string> sup;
        for (int i = 0; i < n; i++)
            rec[recipes[i]] = i;
        for (auto it : supplies)
            sup.insert(it);
        vector<int> ind(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
            for (auto it : ingredients[i])
                if (rec.find(it) != rec.end())
                {
                    adj[rec[it]].push_back(i);
                    ind[i]++;
                }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (ind[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            int cou = 0;
            for (auto i : ingredients[node])
                if (sup.count(i))
                    cou++;
            if (cou == ingredients[node].size())
            {
                ans.push_back(recipes[node]);
                sup.insert(recipes[node]);
            }
            for (auto it : adj[node])
                if (--ind[it] == 0)
                    q.push(it);
        }
        return ans;
    }
};
// @lc code=end
