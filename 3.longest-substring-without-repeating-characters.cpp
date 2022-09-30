/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length(), cou = 0;
        unordered_map<char, int> m;
        int l = 0, r = 0;
        while (r < n)
        {
            while ((r < n) && (m.find(s[r]) == m.end()))
            {
                m[s[r]] += 1;
                r++;
            }
            cou = max(cou, r - l);
            m.erase(s[l]);
            l++;
        }
        return cou;
    }
};
// @lc code=end
