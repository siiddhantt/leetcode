/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, int> dict;
    bool rec(int i, string &s, vector<int> &dp)
    {
        if (i > s.size())
            return false;
        if (i == s.size())
            return true;
        if (dp[i] != -1)
            return dp[i];
        bool res;
        string tmp = "";
        for (int j = i; j < s.size(); j++)
        {
            tmp += s[j];
            if (dict.find(tmp) != dict.end())
                res = rec(j + 1, s, dp);
            if (res)
                return dp[i] = 1;
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size(), -1);
        for (auto it : wordDict)
            dict[it]++;
        return rec(0, s, dp);
    }
};
// @lc code=end
