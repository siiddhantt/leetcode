/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        map<map<char, int>, vector<string>> m;
        for (auto it : strs)
        {
            map<char, int> tmp;
            for (auto i : it)
            {
                tmp[i]++;
            }
            m[tmp].push_back(it);
        }
        for (auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
// @lc code=end
