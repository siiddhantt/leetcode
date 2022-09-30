/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int first = -1;
        int last = -1;
        int res = -1;
        // for first occurence
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (nums[mid] == target)
            {
                res = mid;
                r = mid - 1;
            }
            else if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        first = res;
        l = 0;
        r = nums.size() - 1;
        // for last occurence 
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (nums[mid] == target)
            {
                res = mid;
                l = mid + 1;
            }
            else if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        last = res;
        if (first >= 0 && last >= 0)
        {
            return {first, last};
        }
        else
        {
            return {-1, -1};
        }
    }
};
// @lc code=end
