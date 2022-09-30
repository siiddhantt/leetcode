/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (auto it : nums)
        {
            if (it % 2 == 0)
            {
                it = 0;
            }
            else
            {
                it = 1;
            }
        }
        int sum = 0, cou = 0;
        unordered_map<int, int> m;
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
