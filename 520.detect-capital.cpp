/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size(), cap = 0;
        for (auto it : word)
            if (isupper(it))
                cap++;
        if (cap == 0 || cap == n)
            return true;
        else if (cap == 1 && isupper(word[0]))
            return true;
        return false;
    }
};
// @lc code=end
