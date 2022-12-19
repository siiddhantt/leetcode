/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size(), l = 0, r = 0, ans = INT_MIN, cou = 0;
        while (l <= r && r < n)
        {
            if (cou > k)
            {
                if (nums[l] == 0)
                    cou--;
                l++;
                continue;
            }
            if (nums[r] == 0)
                cou++;
            ans = max(ans, r - l);
            r++;
        }
        if (cou <= k)
            ans = max(ans, r - l);
        return ans;
    }
};
// @lc code=end
