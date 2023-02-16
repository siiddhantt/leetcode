/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int val = 0;
        string s = bitset<32>(n).to_string();
        for (int i = 0; i < 32; i++)
            if (s[i] == '1')
                val |= (1 << i);
        return val;
    }
};
// @lc code=end