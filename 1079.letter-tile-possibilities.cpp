/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, int> m;
    void rec(string &tiles, string &tmp, vector<int> &dp)
    {
        if (tmp.size() > 0 && tmp.size() <= tiles.size())
            m[tmp]++;
        for (int i = 0; i < tiles.size(); i++)
        {
            if (dp[i] == 0)
            {
                tmp += tiles[i];
                dp[i] = 1;
                rec(tiles, tmp, dp);
                tmp.pop_back();
                dp[i] = 0;
            }
        }
    }
    int numTilePossibilities(string tiles)
    {
        string tmp;
        vector<int> dp(tiles.size(), 0);
        rec(tiles, tmp, dp);
        return m.size();
    }
};
// @lc code=end
