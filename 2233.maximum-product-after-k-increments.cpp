/*
 * @lc app=leetcode id=2233 lang=cpp
 *
 * [2233] Maximum Product After K Increments
 */

// @lc code=start
class Solution
{
public:
    int mod = 1e9 + 7;
    int maximumProduct(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : nums)
            pq.push(it);
        while (k > 0)
        {
            int val = pq.top();
            pq.pop();
            pq.push(val + 1);
            k--;
        }
        long long ans = 1;
        while (!pq.empty())
        {
            ans = (ans % mod * pq.top() % mod) % mod;
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
