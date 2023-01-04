/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution
{
public:
    set<vector<int>> st;
    vector<vector<int>> ans;
    void rec(int i, vector<int> &nums, vector<int> &vec, vector<int> &vis)
    {
        if (vec.size() == nums.size())
        {
            if (st.find(vec) != st.end())
                return;
            st.insert(vec);
            ans.push_back(vec);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!vis[i])
            {
                vec.push_back(nums[i]);
                vis[i] = 1;
                rec(i + 1, nums, vec, vis);
                vec.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<int> vis(nums.size(), 0), vec;
        rec(0, nums, vec, vis);
        return ans;
    }
};
// @lc code=end
