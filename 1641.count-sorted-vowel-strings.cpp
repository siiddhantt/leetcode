/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 */

// @lc code=start
class Solution
{
public:
    int cou = 0;
    vector<char> vec{'a', 'e', 'i', 'o', 'u'};
    void rec(int &n, string &tmp, int i)
    {
        if (tmp.size() == n)
        {
            cou++;
            return;
        }
        for (int j = i; j < vec.size(); j++)
        {
            tmp += vec[j];
            rec(n, tmp, j);
            tmp.pop_back();
        }
    }
    int countVowelStrings(int n)
    {
        string tmp;
        rec(n, tmp, 0);
        return cou;
    }
};
// @lc code=end
