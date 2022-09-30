/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
 */

// @lc code=start
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size(), s = 0;
        vector<int> pf(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pf[i] = pf[i - 1] + arr[i - 1];
        }
        int sze = 1;
        while (sze <= n)
        {
            int end = sze, i = 0;
            while (end <= n)
            {
                s += pf[end] - pf[i];
                i++;
                end++;
            }
            sze += 2;
        }
        return s;
    }
};
// @lc code=end
