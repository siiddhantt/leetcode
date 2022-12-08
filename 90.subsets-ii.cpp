/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    vector<int> vec;
    vector<vector<int>> ans;
    void rec(vector<int> &nums, int i, map<map<int, int>, int> &m)
    {
        if (i >= nums.size())
        {
            map<int, int> tmp;
            for (int j = 0; j < vec.size(); j++)
            {
                tmp[vec[j]] += 1;
            }
            if (m.find(tmp) == m.end())
            {
                m[tmp] += 1;
                ans.push_back(vec);
            }
            return;
        }
        vec.push_back(nums[i]);
        rec(nums, i + 1, m);
        vec.pop_back();
        rec(nums, i + 1, m);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        map<map<int, int>, int> m;
        rec(nums, 0, m);
        return ans;
    }
};
// @lc code=end
