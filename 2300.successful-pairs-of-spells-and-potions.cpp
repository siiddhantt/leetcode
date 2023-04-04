/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size(), m = potions.size();
        vector<int> res(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {
            long long curr = spells[i];
            long long l = 0, r = m - 1;
            while (r - l > 1)
            {
                int md = l + (r - l) / 2;
                if (curr * potions[md] >= success)
                    r = md;
                else
                    l = md + 1;
            }
            long long ans = 0;
            if (curr * potions[l] >= success)
                ans = m - l;
            else if (curr * potions[r] >= success)
                ans = m - r;
            res[i] = ans;
        }
        return res;
    }
};
// @lc code=end
