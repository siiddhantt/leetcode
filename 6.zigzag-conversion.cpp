/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int n = s.size(), i = 0, r = 0, c = 0;
        int numCols = 1001;
        vector<vector<char>> vec(numRows, vector<char>(numCols, ' '));
        while (i < n)
        {
            while (r < numRows && i < n)
            {
                vec[r][c] = s[i];
                r++;
                i++;
            }
            r -= 2;
            c += 1;
            while (r > 0 && i < n && c < numCols)
            {
                vec[r][c] = s[i];
                r--;
                i++;
                c++;
            }
        }
        string ans;
        for (auto &row : vec)
            for (auto &charac : row)
                if (charac != ' ')
                    ans += charac;
        return ans;
    }
};
// @lc code=end
