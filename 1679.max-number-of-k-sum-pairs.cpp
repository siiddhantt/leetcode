/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int l = 0, r = nums.size() - 1, cou = 0;
        sort(nums.begin(), nums.end());
        while (l < r)
        {
            if ((nums[l] + nums[r]) == k)
            {
                cou++;
                l++;
                r--;
            }
            else if ((nums[l] + nums[r]) < k)
                l++;
            else
                r--;
        }
        return cou;
    }
};
// @lc code=end
