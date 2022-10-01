/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        if (s == "()")
            return 1;

        int i = 0, j = 1, cnt = 1, score = 0;
        while (i < s.length())
        {
            while (j < s.length() and cnt)
            {
                if (s[j] == '(')
                    cnt++;
                else
                    cnt--;
                j++;
            }

            if (s.substr(i, j - i) == "()")
                score++;
            else
                score += 2 * scoreOfParentheses(s.substr(i + 1, j - i - 2));
            i = j++;
            cnt = 1;
        }

        return score;
    }
};
// @lc code=end
