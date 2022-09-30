/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int l = 0;
        int r = arr.size() - 1;
        int n = arr.size();
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;
            if (mid == 0)
            {
                prev = mid;
            }
            else if (mid == n - 1)
            {
                next = mid;
            }
            if ((arr[mid] > arr[prev]) && (arr[mid] > arr[next]))
            {
                return mid;
            }
            if (arr[prev] > arr[mid])
            {
                r = mid - 1;
            }
            else if (arr[next] > arr[mid])
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
