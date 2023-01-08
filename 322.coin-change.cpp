/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
public:
    map<int, int> m;
    int rec(vector<int> &coins, int amount)
    {
        if (m.find(amount) != m.end())
            return m[amount];
        if (amount == 0)
            return 0;
        if (amount < coins[0])
            return m[amount] = -1;
        int ans = INT_MAX, z = 0;
        for (int i = coins.size() - 1; i >= 0; i--)
        {
            int c;
            if (amount >= coins[i])
            {
                c = 1 + rec(coins, amount - coins[i]);
                if (c == 0)
                {
                    z++;
                    continue;
                }
            }
            else
            {
                z++;
                continue;
            }
            ans = min(ans, c);
        }
        if (z == coins.size())
            return m[amount] = -1;
        return m[amount] = ans;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        return rec(coins, amount);
    }
};
// @lc code=end
