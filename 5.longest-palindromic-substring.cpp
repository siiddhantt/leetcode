/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    vector<int> coor = {0, 0};
    bool isPal(string &s, int i, int j, vector<vector<bool>> &dp)
    {
        if (dp[i][j] != NULL)
            return dp[i][j];
        if (i == j)
            return true;
        else if (j == i + 1)
            return s[i] == s[j];
        dp[i][j] = (s[i] == s[j]) && (isPal(s, i + 1, j - 1, dp));
        if (dp[i][j] == true && ((j - i) > (coor[1] - coor[0])))
            coor[0] = i, coor[1] = j;
        return dp[i][j];
    }
    string longestPalindrome(string s)
    {
        string ans;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, NULL));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == s[i])
                {
                    bool tmp = isPal(s, i, j, dp);
                    if (tmp && ((j - i) > (coor[1] - coor[0])))
                        coor[0] = i, coor[1] = j;
                }
            }
        }
        ans = s.substr(coor[0], coor[1] - coor[0] + 1);
        return ans;
    }
};
// @lc code=end
