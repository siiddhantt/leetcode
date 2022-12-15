/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> cache(size, 1);
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (nums[i] < nums[j])
                {
                    cache[i] = max(cache[i], 1 + cache[j]);
                }
            }
        }
        auto itr = max_element(cache.begin(), cache.end());
        return *itr;
    }
};
// @lc code=end
