/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> m;
    int rec(int n)
    {
        if (n == 2 || n == 3)
            return n;
        if (m.find(n) != m.end())
            return m[n];
        int ans = 1;
        for (int i = 2; i < n - 1; i++)
        {
            int tmp = i * rec(n - i);
            ans = max(ans, tmp);
        }
        return m[n] = ans;
    }
    int integerBreak(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        return rec(n);
    }
};
// @lc code=end
