/*
 * @lc app=leetcode id=1673 lang=cpp
 *
 * [1673] Find the Most Competitive Subsequence
 */

// @lc code=start
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector<int> ans;
        stack<int> stk;
        int n = nums.size(), j = k;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && (i == n || nums[stk.top()] > nums[i]) && n - j > 0)
            {
                stk.pop();
                j++;
            }
            stk.push(i);
        }
        while (!stk.empty())
        {
            int i = stk.top();
            stk.pop();
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return vector<int>(ans.begin(), ans.begin() + k);
    }
};
// @lc code=end
