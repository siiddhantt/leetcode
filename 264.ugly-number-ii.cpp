/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> ans;
        ans.push_back(1);
        int i = 0, j = 0, k = 0;
        while (ans.size() < n)
        {
            ans.push_back(min(ans[i] * 2, min(ans[j] * 3, ans[k] * 5)));
            if (ans.back() == ans[i] * 2)
                i++;
            if (ans.back() == ans[j] * 3)
                j++;
            if (ans.back() == ans[k] * 5)
                k++;
        }
        return ans.back();
    }
};
// @lc code=end
