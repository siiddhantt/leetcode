/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> m;
        multimap<int, char, greater<int>> mm;
        string ans;
        for (char c : s)
        {
            m[c]++;
        }
        for (auto it : m)
        {
            mm.insert({it.second, it.first});
        }
        for (auto it : mm)
        {
            for (int i = 0; i < it.first; i++)
            {
                ans += it.second;
            }
        }
        return ans;
    }
};
// @lc code=end
