/*
 * @lc app=leetcode id=2222 lang=cpp
 *
 * [2222] Number of Ways to Select Buildings
 */

// @lc code=start
class Solution
{
public:
    long long numberOfWays(string s)
    {
        long long ans = 0;
        int n = s.size();
        vector<int> zeroes(n, 0), ones(n, 0);
        if (s[0] == '0')
            zeroes[0]++;
        else
            ones[0]++;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                zeroes[i] = 1 + zeroes[i - 1];
                ones[i] = ones[i - 1];
            }
            else
            {
                zeroes[i] = zeroes[i - 1];
                ones[i] = 1 + ones[i - 1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                ans += ones[i] * (ones[n - 1] - ones[i]);
            else
                ans += zeroes[i] * (zeroes[n - 1] - zeroes[i]);
        }
        return ans;
    }
};
// @lc code=end
