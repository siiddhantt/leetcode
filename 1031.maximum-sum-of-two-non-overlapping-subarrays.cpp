/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
class Solution
{
public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
    {
        int n = nums.size(), ans = 0, s1, s2;
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];
        for (int i = firstLen - 1; i < n; i++)
        {
            if (i == firstLen - 1)
            {
                s1 = nums[i];
                s2 = 0;
                for (int j = i + secondLen; j < n; j++)
                    s2 = max(s2, nums[j] - nums[j - secondLen]);
                ans = max(ans, s1 + s2);
            }
            else
                s1 = nums[i] - nums[i - firstLen];
            s2 = 0;
            for (int j = secondLen - 1; j <= i - firstLen; j++)
            {
                if (j == secondLen - 1)
                    s2 = max(s2, nums[j]);
                else
                    s2 = max(s2, nums[j] - nums[j - secondLen]);
            }
            for (int j = i + secondLen; j < n; j++)
                s2 = max(s2, nums[j] - nums[j - secondLen]);
            ans = max(ans, s1 + s2);
        }
        return ans;
    }
};
// @lc code=end
