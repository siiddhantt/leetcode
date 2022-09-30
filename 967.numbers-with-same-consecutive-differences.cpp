/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution
{
public:
    void generate(string &s, int n, int k, vector<int> &ans)
    {
        if (s.length() == n)
        {
            ans.push_back(stoi(s));
            return;
        }
        for (int i = 0; i <= 9; i++)
        {
            if (s.length() == 0 && i == 0)
            {
                continue;
            }
            if (s.length() != 0 && abs(s[s.length() - 1] - (i + '0')) != k)
            {
                continue;
            }
            s.push_back(i + '0');
            generate(s, n, k, ans);
            s.pop_back();
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans;
        string s;
        generate(s, n, k, ans);
        return ans;
    }
};
// @lc code=end
