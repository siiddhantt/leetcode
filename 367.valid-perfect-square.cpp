/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int l = 0;
        int r = num;
        while (l <= r)
        {
            long long mid = l + ((r - l) / 2);
            long long msqr = mid * mid;
            if (msqr == num)
            {
                return true;
            }
            else if (msqr > num)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end
