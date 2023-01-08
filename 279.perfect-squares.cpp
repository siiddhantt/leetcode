/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> m;
    int rec(int n)
    {
        if (n == 1)
            return 1;
        if (n < 1)
            return 0;
        if (m.find(n) != m.end())
            return m[n];
        int ans = INT_MAX;
        for (int i = 1; i <= sqrt(n); i++)
        {
            int tmp = 1 + rec(n - i * i);
            ans = min(ans, tmp);
        }
        return m[n] = ans;
    }
    int numSquares(int n)
    {
        return rec(n);
    }
};
// @lc code=end
