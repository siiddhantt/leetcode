/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int product(vector<int> &nums)
    {
        int ans = INT_MIN, pro = 1;
        for (auto it : nums)
        {
            pro *= it;
            ans = max(ans, pro);
            if (pro == 0)
                pro = 1;
        }
        return ans;
    }
    int maxProduct(vector<int> &nums)
    {
        int p1 = product(nums);
        reverse(nums.begin(), nums.end());
        int p2 = product(nums);
        return max(p1, p2);
    }
};
// @lc code=end
