/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    set<multiset<int>> st;
    vector<vector<int>> ans;
    void rec(vector<int> &vec, vector<int> &candidates, int target)
    {
        if (target == 0)
        {
            multiset<int> tmp;
            copy(vec.begin(), vec.end(), inserter(tmp, tmp.end()));
            if (st.find(tmp) != st.end())
                return;
            st.insert(tmp);
            ans.push_back(vec);
        }
        if (target < 0)
            return;
        for (auto it : candidates)
        {
            vec.push_back(it);
            rec(vec, candidates, target - it);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> vec;
        rec(vec, candidates, target);
        return ans;
    }
};
// @lc code=end
