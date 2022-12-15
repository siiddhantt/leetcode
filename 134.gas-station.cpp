/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size(), a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            a += cost[i];
            b += gas[i];
        }
        if (b < a)
            return -1;
        int balance = 0, pos = 0;
        for (int i = 0; i < n; i++)
        {
            balance += gas[i] - cost[i];
            if (balance < 0)
            {
                pos = i + 1;
                balance = 0;
            }
        }
        return pos;
    }
};
// @lc code=end
