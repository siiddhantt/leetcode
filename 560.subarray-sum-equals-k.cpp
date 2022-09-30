/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int, int> m;
        int sum = 0, cou = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum == k)
            {
                cou++;
            }
            if (m.find(sum - k) != m.end())
            {
                cou += m[sum - k];
            }
            m[sum] += 1;
        }
        return cou;
    }
};
// @lc code=end
