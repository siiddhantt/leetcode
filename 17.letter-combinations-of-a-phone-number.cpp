/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution
{
public:
    vector<string> rec(int i, string &digits, vector<vector<char>> &vec)
    {
        if (i >= digits.size())
            return {""};
        int val = digits[i] - '0';
        vector<string> v = rec(i + 1, digits, vec), ans;
        for (auto it : vec[val - 1])
            for (auto j : v)
                ans.push_back(it + j);
        return ans;
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        vector<vector<char>> vec = {{}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        return rec(0, digits, vec);
    }
};
// @lc code=end
