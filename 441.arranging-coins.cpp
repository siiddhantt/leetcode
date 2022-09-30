/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long i = 1;
        int cou = 0;
        while (((i * (i + 1)) / 2) <= n)
        {
            cou = i;
            i++;
        }
        return cou;
    }
};
// @lc code=end
