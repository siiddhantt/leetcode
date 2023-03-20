/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (nums[l] == target || nums[r] == target)
            return true;
        return false;
    }
};
// @lc code=end
