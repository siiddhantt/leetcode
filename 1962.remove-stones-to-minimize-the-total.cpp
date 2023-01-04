/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 */

// @lc code=start
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int n = piles.size(), ans = 0;
        priority_queue<int> pq;
        for (auto it : piles)
            pq.push(it);
        for (int i = 0; i < k; i++)
        {
            int tmp = pq.top();
            pq.pop();
            pq.push(ceil(tmp / 2.0));
        }
        for (int i = 0; i < n; i++)
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
