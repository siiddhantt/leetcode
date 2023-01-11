/*
 * @lc app=leetcode id=1884 lang=cpp
 *
 * [1884] Egg Drop With 2 Eggs and N Floors
 */

// @lc code=start
class Solution
{
public:
    // https://www.youtube.com/watch?v=NGtt7GJ1uiM
    int twoEggDrop(int n)
    {
        if (n == 1 || n == 2)
            return n;
        int i, s = 0;
        for (i = 1; i <= n; i++)
        {
            s += i;
            if (s >= n)
                break;
        }
        return i;
    }
};
// @lc code=end
