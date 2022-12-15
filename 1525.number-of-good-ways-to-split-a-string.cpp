/*
 * @lc app=leetcode id=1525 lang=cpp
 *
 * [1525] Number of Good Ways to Split a String
 */

// @lc code=start
class Solution
{
public:
    int numSplits(string s)
    {
        int cou = 0;
        unordered_map<char, int> l, r;
        for (int i = 0; i < s.size(); i++)
            r[s[i]]++;
        for (int i = 0; i < s.size(); i++)
        {
            l[s[i]]++;
            r[s[i]]--;
            if (r[s[i]] == 0)
                r.erase(s[i]);
            if (l.size() == r.size())
                cou++;
        }
        return cou;
    }
};
// @lc code=end
