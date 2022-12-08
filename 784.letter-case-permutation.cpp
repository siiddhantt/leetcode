/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, int> m;
    void rec(string &s, string &tmp, int i)
    {
        if (tmp.size() == s.size())
            m[tmp]++;
        if (i >= s.size())
            return;
        char c = tolower(s[i]);
        tmp += c;
        rec(s, tmp, i + 1);
        tmp.pop_back();
        c = toupper(s[i]);
        tmp += c;
        rec(s, tmp, i + 1);
        tmp.pop_back();
    }
    vector<string> letterCasePermutation(string s)
    {
        string tmp;
        vector<string> ans;
        rec(s, tmp, 0);
        for (auto it : m)
        {
            ans.push_back(it.first);
        }
        return ans;
    }
};
// @lc code=end
