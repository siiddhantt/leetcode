/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> stk;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!stk.empty() && nums[stk.back()] <= nums[i % n])
                stk.pop_back();
            if (!stk.empty())
                ans[i % n] = nums[stk.back()];
            stk.push_back(i % n);
        }
        return ans;
    }
};
// @lc code=end
