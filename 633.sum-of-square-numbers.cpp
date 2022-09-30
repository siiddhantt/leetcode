/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {

        long long n = sqrt(c);
        int i = 0;
        while (i <= n)
        {
            int x = c - i * i;
            double y = sqrt(x);
            int z = sqrt(x);
            if (y * y == z * z)
            {
                return true;
                break;
            }
            i++;
        }

        return false;
    }
};
// @lc code=end
