/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    void generate(vector<int> &vec, vector<int> &nums, vector<vector<int>> &res)
    {
        if(vec.size() == nums.size()) {
            res.push_back(vec);
            return;
        }
        vec.push_back(nums[0]);
        nums.erase(nums.begin());
        generate(vec, nums, res);
        nums.push_back(vec.back());
        vec.pop_back();
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> vec;
        vector<vector<int>> res;
        generate(vec, nums, res);
        return res;
    }
};
// @lc code=end
