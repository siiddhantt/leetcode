/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto it : nums)
        {
            if (m.find(it) != m.end())
                return it;
            m[it] += 1;
        }
        return 1;
    }
};
// @lc code=end
