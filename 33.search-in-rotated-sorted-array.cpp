/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int bsearch(vector<int> &arr, int i, int j, int t)
    {
        while (i <= j)
        {
            int mid = i + ((j - i) / 2);
            if (arr[mid] == t)
            {
                return mid;
            }
            else if (t < arr[mid])
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        int ind_min = 1;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;
            if ((nums[mid] <= nums[prev]) && (nums[mid] <= nums[next]))
            {
                ind_min = mid;
                r = -1;
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
        l = 0;
        r = n - 1;
        int res1 = bsearch(nums, l, ind_min - 1, target);
        int res2 = bsearch(nums, ind_min, r, target);
        if (res1 != -1)
        {
            return res1;
        }
        else if (res2 != -1)
        {
            return res2;
        }
        return -1;
    }
};
// @lc code=end
