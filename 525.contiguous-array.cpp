/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int ans = INT_MIN;
        int cou = 0, n = nums.size();
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                cou--;
            else
                cou++;
            if (cou == 0)
                ans = max(ans, i + 1);
            m[cou].push_back(i);
        }
        for (auto it : m)
        {
            ans = max(ans, it.second.back() - it.second.front());
        }
        return ans;
    }
};
// @lc code=end
