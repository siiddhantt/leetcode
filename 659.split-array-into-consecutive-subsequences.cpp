/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> m1, m2;
        for (auto it : nums)
        {
            m1[it] += 1;
        }
        for (auto it : nums)
        {
            if (m1[it] <= 0)
                continue;
            if (m2[it - 1] > 0)
            {
                m2[it - 1]--;
                m1[it]--;
                m2[it]++;
            }
            else if (m1[it + 1] && m1[it + 2])
            {
                m1[it]--;
                m1[it + 1]--;
                m1[it + 2]--;
                m2[it + 2]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
