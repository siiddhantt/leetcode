/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution
{
public:
    int cal(int l, int r, char op)
    {
        if (op == '+')
            return l + r;
        else if (op == '-')
            return l - r;
        else
            return l * r;
    }
    vector<int> rec(string s)
    {
        if (s.size() < 3)
            return {stoi(s)};
        vector<int> l, r, ans;
        int j = 0;
        while (j < s.size())
        {
            if (s[j] == '+' || s[j] == '-' || s[j] == '*')
            {
                l = rec(s.substr(0, j));
                r = rec(s.substr(j + 1));
                for (int a : l)
                {
                    for (int b : r)
                    {
                        ans.push_back(cal(a, b, s[j]));
                    }
                }
            }
            j++;
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression)
    {
        auto ans = rec(expression);
        return ans;
    }
};
// @lc code=end
