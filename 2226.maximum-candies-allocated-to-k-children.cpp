/*
 * @lc app=leetcode id=2226 lang=cpp
 *
 * [2226] Maximum Candies Allocated to K Children
 */

// @lc code=start
class Solution
{
public:
    bool isPossible(long long c, long long k, vector<int> &candies)
    {
        long long sum = 0;
        for (auto it : candies)
        {
            long long q = it / c;
            sum += q;
        }
        if (sum >= k)
            return true;
        return false;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long l = 1, r = 1e7, mid;
        while (r - l > 1)
        {
            mid = l + (r - l) / 2;
            if (isPossible(mid, k, candies))
                l = mid;
            else
                r = mid - 1;
        }
        if (isPossible(r, k, candies))
            return r;
        else if (isPossible(l, k, candies))
            return l;
        return 0;
    }
};
// @lc code=end
