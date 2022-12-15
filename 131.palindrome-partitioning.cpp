/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
public:
    bool isPal(string s)
    {
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s[i] != s[s.length() - i - 1])
                return false;
        }
        return true;
    }
    vector<vector<string>> rec(string s, int i)
    {
        vector<vector<string>> ans;
        if (i == s.size() - 1)
        {
            string ts(1, s[i]);
            vector<string> t = {ts};
            ans.push_back(t);
            return ans;
        }
        for (int j = i; j < s.size(); j++)
        {
            string tmp = s.substr(i, j - i + 1);
            vector<string> l;
            if (isPal(tmp))
                l.push_back(tmp);
            else
                continue;
            vector<vector<string>> r = rec(s, j + 1);
            for (auto it : r)
            {
                vector<string> res;
                res.insert(res.begin(), l.begin(), l.end());
                res.insert(res.end(), it.begin(), it.end());
                ans.push_back(res);
            }
            if (r.size() == 0 && l.size() != 0)
                ans.push_back(l);
        }
        return ans;
    }
    vector<vector<string>> partition(string s)
    {
        return rec(s, 0);
    }
};
// @lc code=end
