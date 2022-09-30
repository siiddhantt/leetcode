/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        int prev2 = 0;
        int prev1 = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        if (n != 0)
            return prev1;
        return 0;
    }
};
// @lc code=end
