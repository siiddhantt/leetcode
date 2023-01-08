/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 */

// @lc code=start
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int i = 0;
        while (i < costs.size() && costs[i] <= coins)
        {
            coins -= costs[i];
            i++;
        }
        return i;
    }
};
// @lc code=end
