/*
 * @lc app=leetcode id=2279 lang=cpp
 *
 * [2279] Maximum Bags With Full Capacity of Rocks
 */

// @lc code=start
class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = capacity.size(), cou = 0;
        for (int i = 0; i < n; i++)
            capacity[i] -= rocks[i];
        sort(capacity.begin(), capacity.end());
        for (auto it : capacity)
        {
            additionalRocks -= it;
            if (additionalRocks >= 0)
                cou++;
            else
                break;
        }
        return cou;
    }
};
// @lc code=end
