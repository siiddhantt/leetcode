/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void rec(int i, vector<int> vec, int k, int n)
    {
        if (vec.size() == k || n == 0)
        {
            if (vec.size() == k && n != 0)
                return;
            else if (vec.size() != k && n == 0)
                return;
            else
                ans.push_back(vec);
        }
        for (int j = i; j < 10; j++)
        {
            if (j > n)
                break;
            vec.push_back(j);
            rec(j + 1, vec, k, n - j);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> vec;
        rec(1, vec, k, n);
        return ans;
    }
};
// @lc code=end
