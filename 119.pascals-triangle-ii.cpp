/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        // nth row = NC0, NC1, ......, NCN - 1, NCN
        // NCr = (NCr - 1 * (N - r + 1)) / r where 1 ≤ r ≤ N

        long long val = 1;
        vector<int> vec;
        vec.push_back(val);
        for (int i = 1; i <= rowIndex; i++)
        {
            val = (val * (rowIndex - i + 1)) / i;
            vec.push_back(val);
        }
        return vec;
    }
};
// @lc code=end
