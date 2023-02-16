/*
 * @lc app=leetcode id=1712 lang=cpp
 *
 * [1712] Ways to Split Array Into Three Subarrays
 */

// @lc code=start
class Solution
{
public:
    int left(int i, int j, int idx, vector<int> &pre)
    {
        int ans = pre.size();
        while (i <= j)
        {
            int m = i + (j - i) / 2;
            if (pre[m] >= 2 * pre[idx])
            {
                ans = m;
                j = m - 1;
            }
            else
                i = m + 1;
        }
        return ans;
    }
    int right(int i, int j, int idx, vector<int> &pre)
    {
        int ans = idx;
        while (i <= j)
        {
            int m = i + (j - i) / 2;
            if (pre[m] <= (pre.back() + pre[idx]) / 2)
            {
                ans = m;
                i = m + 1;
            }
            else
                j = m - 1;
        }
        return ans;
    }
    int waysToSplit(vector<int> &nums)
    {
        vector<int> pre = nums;
        int n = nums.size(), ans = 0, mod = 1e9 + 7;
        for (int i = 1; i < n; i++)
            pre[i] += pre[i - 1];
        for (int i = 0; i < n - 2; i++)
        {
            int l = left(i + 1, n - 2, i, pre);
            int r = right(i + 1, n - 2, i, pre);
            if (r >= l)
                ans = ((ans % mod) + (r - l + 1) % mod) % mod;
        }
        return ans;
    }
};
// @lc code=end
