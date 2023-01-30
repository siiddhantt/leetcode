/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        if (left == right)
            return left;
        long long val = left;
        for (long long i = left + 1; i <= right; i++)
        {
            val &= i;
            if (val == 0)
                return 0;
        }
        return val;
    }
};
// @lc code=end
