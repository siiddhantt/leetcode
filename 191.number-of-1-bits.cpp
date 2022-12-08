/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int cou = 0;
        for (int i = 0; i < 32; i++)
        {
            int p = (1 << i) & n;
            if (p != 0)
                cou++;
        }
        return cou;
    }
};
// @lc code=end
