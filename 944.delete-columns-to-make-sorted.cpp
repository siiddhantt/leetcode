/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs[0].size(), cou = 0;
        for (int i = 0; i < n; i++)
        {
            char prev = 'a';
            for (auto it : strs)
            {
                if (it[i] >= prev)
                    prev = it[i];
                else
                {
                    cou++;
                    break;
                }
            }
        }
        return cou;
    }
};
// @lc code=end
