/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution
{
public:
    set<int> convertToSet(vector<int> v)
    {
        set<int> s(v.begin(), v.end());

        return s;
    }

    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s;
        s = convertToSet(nums);
        if (s.size() == nums.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
// @lc code=end
