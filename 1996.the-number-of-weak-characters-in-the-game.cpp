/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 */

// @lc code=start
class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        multimap<int, int> m, n;
        // vector<int> n;
        for (int i = 0; i < properties.size(); i++)
        {
            m[properties[i][0]] = properties[i][1];
            n[properties[i][1]] = properties[i][0];
        }
        // sort(n.begin(), n.end());
        int i = 0, res = 0;
        for (auto it : m)
        {
            if (n[i] > it.second[1])
            {
                res++;
            }
            i++;
            if (i == m.size() - 1)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
