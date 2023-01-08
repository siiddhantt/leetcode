/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        unordered_map<string, int> m;
        string wind = s.substr(0, 10);
        int r = 9;
        while (r < s.size())
        {
            if (m.find(wind) != m.end())
            {
                if (m[wind] != -1)
                {
                    ans.push_back(wind);
                    m[wind] = -1;
                }
            }
            else
                m[wind] = 1;
            wind.erase(wind.begin());
            wind.push_back(s[++r]);
        }
        return ans;
    }
};
// @lc code=end
