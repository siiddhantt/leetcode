/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size(), xors = 0;
        int k = (1 << maximumBit);
        vector<int> ans;
        for (auto it : nums)
        {
            xors ^= it;
        }
        for (int i = 0; i < n; i++)
        {
            int tmp = xors ^ (k - 1);
            ans.push_back(tmp);
            xors ^= nums[n - 1 - i];
        }
        return ans;
    }
};
// @lc code=end
