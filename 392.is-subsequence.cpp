/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int l = 0;
        for (char c : s)
        {
            int i;
            for (i = l; i < t.size(); i++)
            {
                if (c == t[i])
                {
                    l = i + 1;
                    break;
                }
            }
            if (i == t.size())
                return false;
        }
        return true;
    }
};
// @lc code=end
