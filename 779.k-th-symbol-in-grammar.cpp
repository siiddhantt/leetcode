/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution
{
public:
    string rec(int n, int k)
    {
        if (n == 1)
            return "0";
        string prev = rec(n - 1, (k + 1) / 2);
        if (prev == "0")
        {
            if (k % 2 == 0)
                return "1";
            else
                return "0";
        }
        else
        {
            if (k % 2 == 0)
                return "0";
            else
                return "1";
        }
    }
    int kthGrammar(int n, int k)
    {
        string ans = rec(n, k);
        if (ans == "0")
            return 0;
        return 1;
    }
};
// @lc code=end
