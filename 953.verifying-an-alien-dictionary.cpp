/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int n = words.size();
        unordered_map<char, int> dict;
        for (int i = 0; i < order.size(); i++)
            dict[order[i]] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int flg = 0;
                for (int k = 0; k < min(words[i].size(), words[j].size()); k++)
                {
                    if (dict[words[i][k]] < dict[words[j][k]])
                    {
                        flg = 1;
                        break;
                    }
                    else if (dict[words[i][k]] == dict[words[j][k]])
                        continue;
                    else
                        return false;
                }
                if (flg == 0)
                    if (words[i].size() > words[j].size())
                        return false;
            }
        }
        return true;
    }
};
// @lc code=end
