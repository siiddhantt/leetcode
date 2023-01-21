/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// @lc code=start
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        int n = pattern.size();
        for (auto it : words)
        {
            int flag = 0;
            unordered_map<char, char> m;
            unordered_map<char, int> cou;
            for (int i = 0; i < n; i++)
            {
                if (m.find(pattern[i]) != m.end())
                {
                    if (m[pattern[i]] == it[i])
                        continue;
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    if (cou[it[i]] > 0)
                    {
                        flag = 1;
                        break;
                    }
                    m[pattern[i]] = it[i];
                    cou[it[i]]++;
                }
            }
            if (flag == 0)
                ans.push_back(it);
        }
        return ans;
    }
};
// @lc code=end
