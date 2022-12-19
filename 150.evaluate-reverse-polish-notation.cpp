/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (auto it : tokens)
        {
            if (it != "+" && it != "-" && it != "*" && it != "/")
                s.push(stoi(it));
            else
            {
                long long v2 = s.top();
                s.pop();
                long long v1 = s.top();
                s.pop();
                long long eval;
                if (it == "+")
                    eval = v1 + v2;
                else if (it == "-")
                    eval = v1 - v2;
                else if (it == "*")
                    eval = v1 * v2;
                else
                    eval = v1 / v2;
                s.push(eval);
            }
        }
        return s.top();
    }
};
// @lc code=end
