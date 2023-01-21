/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution
{
public:
    void rec(string s, int i, int dots, string currIp, vector<string> &res)
    {
        if (dots == 4 && i == s.length())
        {
            res.push_back(currIp.substr(0, currIp.length() - 1));
            return;
        }
        if (dots > 4)
            return;
        for (int j = i; j < min(i + 3, (int)s.length()); j++)
            if (stoi(s.substr(i, j - i + 1)) < 256 && (i == j || s[i] != '0'))
                rec(s, j + 1, dots + 1, currIp + s.substr(i, j - i + 1) + ".", res);
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        if (s.length() > 12)
            return ans;
        rec(s, 0, 0, "", ans);
        return ans;
    }
};
// @lc code=end
