/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void rec(int i, vector<int> &vec, vector<int> &candidates, int target)
    {
        if (target == 0)
        {
            ans.push_back(vec);
            return;
        }
        for (int j = i; j < candidates.size(); j++)
        {
            if (candidates[j] > target)
                break;
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            vec.push_back(candidates[j]);
            rec(j + 1, vec, candidates, target - candidates[j]);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> vec;
        sort(candidates.begin(), candidates.end());
        rec(0, vec, candidates, target);
        return ans;
    }
};
// @lc code=end
