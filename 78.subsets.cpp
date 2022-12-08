/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> vec;
    void rec(vector<int> &nums, int i)
    {
        if (i >= nums.size())
        {
            ans.push_back(vec);
            return;
        }
        vec.push_back(nums[i]);
        rec(nums, i + 1);
        vec.pop_back();
        rec(nums, i + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int i = 0;
        rec(nums, i);
        return ans;
    }
};
// @lc code=end
