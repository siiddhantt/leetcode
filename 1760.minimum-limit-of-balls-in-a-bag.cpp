/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
class Solution
{
public:
    bool isValid(int p, vector<int> &nums, int maxOp)
    {
        int cou = 0;
        for (auto it : nums)
        {
            int q = (it - 1) / p;
            cou += q;
        }
        return cou <= maxOp;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 1, r = 1e9, ans;
        while (r - l > 1)
        {
            int md = l + (r - l) / 2;
            if (isValid(md, nums, maxOperations))
                r = md;
            else
                l = md + 1;
        }
        if (isValid(l, nums, maxOperations))
            ans = l;
        else if (isValid(r, nums, maxOperations))
            ans = r;
        return ans;
    }
};
// @lc code=end
