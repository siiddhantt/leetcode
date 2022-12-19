/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size(), l = 0, r = 0, ans = INT_MIN, cou = 0;
        while (l <= r && r < n)
        {
            if (cou > 1)
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
        if (cou <= 1)
            ans = max(ans, r - l);
        return ans - 1;
    }
};
// @lc code=end
