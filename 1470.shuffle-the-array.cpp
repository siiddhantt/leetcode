/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ans;
        int i1 = 0, i2 = n;
        while (i1 < n && i2 < 2 * n)
        {
            ans.push_back(nums[i1++]);
            ans.push_back(nums[i2++]);
        }
        return ans;
    }
};
// @lc code=end
