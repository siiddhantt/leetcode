/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int firstPos(vector<int> &nums, int t)
    {
        int l = 0, r = nums.size() - 1;
        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == t)
                r = mid;
            else if (nums[mid] > t)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (nums[l] == t)
            return l;
        if (nums[r] == t)
            return r;
        return -1;
    }
    int lastPos(vector<int> &nums, int t)
    {
        int l = 0, r = nums.size() - 1;
        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == t)
                l = mid;
            else if (nums[mid] > t)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (nums[r] == t)
            return r;
        if (nums[l] == t)
            return l;
        return -1;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        return {firstPos(nums, target), lastPos(nums, target)};
    }
};
// @lc code=end
