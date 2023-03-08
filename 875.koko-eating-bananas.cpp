/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution
{
public:
    long long num(long long n, vector<int> &piles)
    {
        long long cou = 0;
        long double val;
        for (auto it : piles)
        {
            val = (it * 1.0) / (n * 1.0);
            cou += ceil(val);
        }
        return cou;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int l = 1, r = piles[n - 1], m;
        m = l + (r - l) / 2;
        while (l <= r)
        {
            if (num(m, piles) > h)
                l = m + 1;
            else
                r = m - 1;
            m = l + (r - l) / 2;
        }
        return m;
    }
};
// @lc code=end
