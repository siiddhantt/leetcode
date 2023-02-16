/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        unordered_map<int, int> m;
        stack<int> s;
        int n = pushed.size(), cpop = 0;
        for (int i = 0; i < n; i++)
        {
            s.push(pushed[i]);
            m[pushed[i]]++;
            while (m.find(popped[cpop]) != m.end())
            {
                if (s.top() != popped[cpop])
                    break;
                s.pop();
                if (++cpop >= n)
                    break;
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};
// @lc code=end
