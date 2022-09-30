/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        int tmp = n;
        bool res = true;
        unordered_map<int, int> m1, m2;
        while (tmp != 0)
        {
            m1[tmp % 10] += 1;
            tmp = tmp / 10;
        }
        for (int i = 0; i < 31; i++)
        {
            tmp = pow(2, i);
            while (tmp != 0)
            {
                m2[tmp % 10] += 1;
                tmp = tmp / 10;
            }
            if (m1 == m2)
            {
                return true;
            }
            m2.clear();
        }
        return false;
    }
};
// @lc code=end
