/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;
            if ((nums[mid] <= nums[prev]) && (nums[mid] <= nums[next]))
            {
                return nums[mid];
            }
            else if (nums[mid] <= nums[r])
            {
                r = mid - 1;
            }
            else if (nums[l] <= nums[mid])
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
