/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        s += "z";
        unordered_map<char, int> m;
        int n = s.size(), l = 0, r = 0, cou = 0;
        while (l <= r && r < n)
        {
            if (m['a'] > 0 && m['b'] > 0 && m['c'] > 0)
            {
                cou += n - r;
                m[s[l]]--;
                l++;
            }
            else
                m[s[r++]]++;
        }
        return cou;
    }
};
// @lc code=end
