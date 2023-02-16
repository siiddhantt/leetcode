/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start
class Solution
{
public:
    string rinv(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string rec(int n)
    {
        if (n == 1)
            return "0";
        string s = rec(n - 1);
        string ans = s + "1" + rinv(s);
        return ans;
    }
    char findKthBit(int n, int k)
    {
        string ans = rec(n);
        return ans[k - 1];
    }
};
// @lc code=end
