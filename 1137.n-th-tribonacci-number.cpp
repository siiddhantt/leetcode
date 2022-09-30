/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;
        for (int i = 3; i <= n; i++)
        {
            int curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        if (n != 0)
            return prev1;
        return 0;
    }
};
// @lc code=end
