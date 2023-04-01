/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        int n = num_people;
        vector<int> ans(n);
        for (int i = 0; candies > 0; ++i)
        {
            ans[i % n] += min(i + 1, candies);
            candies -= i + 1;
        }
        return ans;
    }
};
// @lc code=end
