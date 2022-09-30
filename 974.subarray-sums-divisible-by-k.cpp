/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0, cou = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum %= k;
            if (sum < 0)
            {
                sum += k;
            }
            cou += m[sum];
            m[sum] += 1;
        }
        return cou;
    }
};
// @lc code=end
