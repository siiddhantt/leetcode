/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<double> time(n);
        for (int i = 0; i < n; i++)
            time[i] = dist[i] * 1.0 / speed[i];
        sort(time.begin(), time.end());
        int ans = 0, curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr < time[i])
            {
                ans += 1;
                curr++;
            }
            else
                break;
        }
        return ans;
    }
};
// @lc code=end
