/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */

// @lc code=start
class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size(), ans = INT_MIN;
        for (int i = n; i >= 1; i--)
        {
            int s = 0, num = i;
            for (int j = n - 1; j >= (n - i); j--)
            {
                s += satisfaction[j] * num;
                num--;
            }
            ans = max(ans, s);
        }
        if (ans < 0)
            return 0;
        return ans;
    }
};
// @lc code=end
