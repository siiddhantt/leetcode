/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */

// @lc code=start
class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        unordered_set<int> ans, curr, prev;
        for (auto it : arr)
        {
            curr = {it};
            for (auto i : prev)
                curr.insert(i | it);
            prev = curr;
            for (auto i : prev)
                ans.insert(i);
        }
        return ans.size();
    }
};
// @lc code=end
