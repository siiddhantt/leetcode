/*
 * @lc app=leetcode id=1546 lang=cpp
 *
 * [1546] Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
 */

// @lc code=start
class Solution
{
public:
    int maxNonOverlapping(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        m[0] = -1;
        int n = nums.size(), sum = 0, cou = 0, r = -1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (m.find(sum - target) != m.end())
            {
                int l = m[sum - target];
                if (r <= l)
                {
                    cou++;
                    r = i;
                }
            }
            m[sum] = i;
        }
        return cou;
    }
};
// @lc code=end
