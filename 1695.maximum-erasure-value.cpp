/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        map<int, int> m;
        int n = nums.size(), l = 0, r = 0, s = 0, ans = INT_MIN;
        while (l <= r && r < n)
        {
            if (m[nums[r]] == 0)
            {
                m[nums[r]]++;
                s += nums[r];
                r++;
            }
            else
            {
                s -= nums[l];
                m[nums[l++]]--;
            }
            ans = max(ans, s);
        }
        return ans;
    }
};
// @lc code=end
