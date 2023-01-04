/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int x = start ^ goal;
        return __builtin_popcount(x);
    }
};
// @lc code=end
