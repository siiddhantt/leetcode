/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        unordered_set<int> pre;
        int mask = 0, max = 0, curr_max = 0;
        for (int i = 31; i >= 0; i--)
        {
            mask |= (1 << i);
            curr_max = max | (1 << i);
            for (auto it : nums)
                pre.insert(it & mask);
            for (auto it : pre)
            {
                if (pre.count(it ^ curr_max) != 0)
                {
                    max = curr_max;
                    break;
                }
            }
            pre.clear();
        }
        return max;
    }
};
// @lc code=end
