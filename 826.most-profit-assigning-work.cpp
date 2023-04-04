/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int curr = INT_MIN;
        int n = difficulty.size(), m = worker.size();
        vector<vector<int>> vec(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            vec[i][0] = difficulty[i];
            vec[i][1] = profit[i];
        }
        sort(vec.begin(), vec.end());
        vector<int> curr_m(n);
        for (int i = 0; i < n; i++)
        {
            curr_m[i] = max(curr, vec[i][1]);
            curr = curr_m[i];
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int l = 0, r = n - 1;
            while (r - l > 1)
            {
                int md = l + (r - l) / 2;
                if (vec[md][0] <= worker[i])
                    l = md;
                else
                    r = md - 1;
            }
            if (vec[r][0] <= worker[i])
                ans += curr_m[r];
            else if (vec[l][0] <= worker[i])
                ans += curr_m[l];
        }
        return ans;
    }
};
// @lc code=end
