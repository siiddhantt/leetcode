/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        int curr = nums[0], cou = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]] > 0)
            {
                int tmp = nums[i];
                nums[i] = curr + 1;
                cou += nums[i] - tmp;
            }
            m[nums[i]]++;
            curr = max(curr, nums[i]);
        }
        return cou;
    }
};
// @lc code=end
