/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void rec(int i, int n, int k, vector<int> &tmp)
    {
        if (tmp.size() == k)
        {
            ans.push_back(tmp);
            return;
        }
        if (i > n)
            return;
        tmp.push_back(i);
        rec(i + 1, n, k, tmp);
        tmp.pop_back();
        rec(i + 1, n, k, tmp);
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> tmp;
        rec(1, n, k, tmp);
        return ans;
    }
};
// @lc code=end
