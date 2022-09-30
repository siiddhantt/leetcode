/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        int lval = 1;
        int rval = 1;
        vector<vector<int>> vec;
        vector<int> tmp;
        for (int i = 0; i < numRows; i++)
        {
            tmp.clear();
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    tmp.push_back(1);
                    continue;
                }
                lval = vec[i - 1][(j - 1)];
                rval = vec[i - 1][j];
                tmp.push_back(lval + rval);
            }
            vec.push_back(tmp);
        }
        return vec;
    }
};
// @lc code=end
