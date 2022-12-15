/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution
{
public:
    int rec(string &text1, int i, string &text2, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i] == text2[j])
            return dp[i][j] = 1 + rec(text1, i - 1, text2, j - 1, dp);
        return dp[i][j] = max(rec(text1, i - 1, text2, j, dp), rec(text1, i, text2, j - 1, dp));
    }
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rec(s, n - 1, rev, n - 1, dp);
    }
};
// @lc code=end
