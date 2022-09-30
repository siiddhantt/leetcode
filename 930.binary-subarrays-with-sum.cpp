/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int sum = 0, cou = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum == goal)
            {
                cou++;
            }
            if (m.find(sum - goal) != m.end())
            {
                cou += m[sum - goal];
            }
            m[sum] += 1;
        }
        return cou;
    }
};
// @lc code=end
