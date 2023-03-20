/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution
{
public:
    bool isValid(int div, int th, vector<int> &nums)
    {
        int sum = 0;
        for (auto it : nums)
        {
            int q = ceil(it * 1.0 / div * 1.0);
            sum += q;
        }
        if (sum <= th)
            return true;
        return false;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        long long l = 1, r = 1e6;
        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if (isValid(mid, threshold, nums))
                r = mid;
            else
                l = mid + 1;
        }
        if (isValid(l, threshold, nums))
            return l;
        else
            return r;
    }
};
// @lc code=end
