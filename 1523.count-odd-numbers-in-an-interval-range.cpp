/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution
{
public:
    int countOdds(int low, int high)
    {
        int cou = 0, diff;
        diff = high - low;
        if (diff == 0)
        {
            if (low % 2 != 0)
                return 1;
            else
                return 0;
        }
        if (low == 0)
            low = 1;
        if (high == 0)
            high = 1;
        diff = high - low;
        if (low % 2 == 0 && diff % 2 == 0)
            cou = diff / 2;
        else if (low % 2 == 0 && diff % 2 != 0)
            cou = (diff + 1) / 2;
        else
            cou = (diff / 2) + 1;
        return cou;
    }
};
// @lc code=end
