/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.length();
        int l = 0, r = 0, ans = 0;
        while (l < n)
        {
            if (colors[l] == colors[r])
            {
                r += 1;
                continue;
            }
            int tmp = 0, curm = 0;
            for (int i = l; i < r; i++)
            {
                tmp += neededTime[i];
                curm = max(curm, neededTime[i]);
            }
            tmp -= curm;
            ans += tmp;
            l = r;
        }
        return ans;
    }
};
// @lc code=end
