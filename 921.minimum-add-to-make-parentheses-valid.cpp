/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int cou = 0;
        queue<char> q;
        for (auto it : s)
        {
            if (it == '(')
            {
                q.push(it);
            }
            else
            {
                if (q.front() != '(')
                {
                    cou++;
                    continue;
                }
                q.pop();
            }
        }
        return (q.size() != -1) ? cou + q.size() : cou;
    }
};
// @lc code=end
