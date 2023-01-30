/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> m1, m2;
        int n1 = s1.size(), n2 = s2.size(), l = 0, r = 0;
        r = n1 - 1;
        if (n1 > n2)
            return false;
        for (int i = 0; i <= r; i++)
        {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        while (r < n2)
        {
            if (m1 == m2)
                return true;
            m2[s2[++r]]++;
            if (m2[s2[l]] == 1)
                m2.erase(s2[l++]);
            else
                m2[s2[l++]]--;
        }
        return false;
    }
};
// @lc code=end
