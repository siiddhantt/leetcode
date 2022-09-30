/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 1;
        int r = x;
        long long mid, ans;
        while (l <= r)
        {
            mid = l + ((r - l) / 2);
            long long msqr = mid * mid;
            if (msqr == x)
            {
                return mid;
            }
            else if (msqr < x)
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
