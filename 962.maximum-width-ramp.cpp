/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        stack<int> stk;
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (stk.empty() || nums[stk.top()] > nums[i])
                stk.push(i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && nums[i] >= nums[stk.top()])
            {
                ans = max(ans, i - stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};
// @lc code=end
