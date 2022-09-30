/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int k = p.length();
        if (k > s.length())
        {
            return {};
        }
        int l = 0, r = k - 1;
        vector<char> vec(s.begin(), s.end());
        vector<int> res;
        unordered_map<char, int> ms, mp;
        for (auto it : p)
        {
            mp[it] += 1;
        }
        for (auto it : vec)
        {
            ms[it] = 0;
            if (mp.find(it) == mp.end())
            {
                mp[it] = 0;
            }
        }
        for (int i = 0; i < r; i++)
        {
            ms[vec[i]] += 1;
        }
        while (r < vec.size())
        {
            ms[vec[r]] += 1;
            if (ms == mp)
            {
                res.push_back(r - k + 1);
            }
            r++;
            ms[vec[l++]] -= 1;
        }
        return res;
    }
};
// @lc code=end
