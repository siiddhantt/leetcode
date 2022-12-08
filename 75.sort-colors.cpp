/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> ans;
        map<int, int> m;
        for (auto it : nums)
        {
            m[it] += 1;
        }
        for (auto it : m)
        {
            for (int i = 0; i < it.second; i++)
                ans.push_back(it.first);
        }
        nums = ans;
    }
};
// @lc code=end
