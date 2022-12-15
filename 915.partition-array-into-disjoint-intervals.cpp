/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */

// @lc code=start
class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> m(n);
        m[0] = nums[0];

        for (int j = 0, i = 1; i != n; j++, i++)
            m[i] = max(m[j], nums[i]);

        int rm = nums[n - 1], answer = INT_MAX;
        for (int j = n - 2, i = n - 1; i; j--, i--)
        {
            rm = min(rm, nums[i]);
            if (m[j] <= rm)
                answer = i;
        }
        return answer == INT_MAX ? 0 : answer;
    }
};
// @lc code=end
