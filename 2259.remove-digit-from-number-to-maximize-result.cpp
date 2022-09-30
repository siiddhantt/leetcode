/*
 * @lc app=leetcode id=2259 lang=cpp
 *
 * [2259] Remove Digit From Number to Maximize Result
 */

// @lc code=start
class Solution
{
public:
    string removeDigit(string num, char ch)
    {
        priority_queue<string> pq;
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] == ch)
            {
                string s = num;
                s.erase(s.begin() + i);
                pq.push(s);
            }
        }
        return pq.top();
    }
};
// @lc code=end
