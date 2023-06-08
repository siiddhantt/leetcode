/*
 * @lc app=leetcode id=2064 lang=cpp
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */

// @lc code=start
class Solution
{
public:
    bool isValid(int val, int n, vector<int> &q)
    {
        int cou = 0;
        for (auto it : q)
        {
            if (it % val == 0)
                cou += it / val;
            else
                cou += (it / val) + 1;
        }
        return cou <= n;
    }
    int minimizedMaximum(int n, vector<int> &q)
    {
        int l = 1, r = 1e5, ans;
        while (r - l > 1)
        {
            int md = (l + r) >> 1;
            if (isValid(md, n, q))
                r = md;
            else
                l = md + 1;
        }
        if (isValid(l, n, q))
            ans = l;
        else if (isValid(r, n, q))
            ans = r;
        return ans;
    }
};
// @lc code=end
