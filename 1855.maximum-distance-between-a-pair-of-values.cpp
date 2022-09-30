/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
class Solution
{
public:
    int bsearch(vector<int> &arr, int i, int j, int t)
    {
        int mid;
        int start = i;
        int res = -1;
        while (i <= j)
        {
            mid = i + ((j - i) / 2);
            if (arr[mid] == t)
            {
                res = mid;
                i = mid + 1;
            }
            else if (t < arr[mid])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        if (i > (arr.size() - 1) || j < start)
        {
            return max(res, mid);
        }
        return max(res, (mid - 1));
    }
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int dis = 0;
        for (int i = 0; i < n1; i++)
        {
            int curr = nums1[i];
            int pos = bsearch(nums2, i, nums2.size() - 1, curr);
            if (pos)
            {
                dis = max(dis, pos - i);
            }
        }
        return dis;
    }
};
// @lc code=end
