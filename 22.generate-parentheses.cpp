/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    void generate(string &s, int open, int close, vector<string> &ans)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(s);
            return;
        }
        if (open > 0)
        {
            s.push_back('(');
            generate(s, open - 1, close, ans);
            s.pop_back();
        }
        if (close > 0)
        {
            if (open < close)
            {
                s.push_back(')');
                generate(s, open, close - 1, ans);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string s;
        vector<string> ans;
        generate(s, n, n, ans);
        return ans;
    }
};
// @lc code=end
