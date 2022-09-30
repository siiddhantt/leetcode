/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> m1, m2;
        for (auto it : ransomNote)
        {
            m1[it] += 1;
        }
        for (auto it : magazine)
        {
            m2[it] += 1;
        }
        for (auto it : m1)
        {
            if (m2[it.first] >= it.second)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
