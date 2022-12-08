/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int min = INT_MAX, n = nums.size() - 1, ans = 0;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1, k = n;
            while (j < k)
            {
                int x = abs((nums[i] + nums[j] + nums[k]) - target);
                if (x == 0)
                {
                    return (nums[i] + nums[j] + nums[k]);
                }
                if (x < min)
                {
                    min = x;
                    ans = nums[i] + nums[j] + nums[k];
                }
                if ((nums[i] + nums[j] + nums[k]) > target)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};
// @lc code=end
