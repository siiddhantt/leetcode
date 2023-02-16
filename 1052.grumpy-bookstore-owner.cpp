/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size(), sat = 0;
        for (int i = 0; i < n; i++)
            if (grumpy[i] == 0)
                sat += customers[i];
        int l = 0, r = 0, curr = 0, ans = INT_MIN;
        while (r < n)
        {
            if (r - l >= minutes)
            {
                if (grumpy[l] == 1)
                    curr -= customers[l];
                l++;
                continue;
            }
            if (grumpy[r] == 1)
                curr += customers[r];
            r++;
            ans = max(ans, curr);
        }
        return sat + ans;
    }
};
// @lc code=end
