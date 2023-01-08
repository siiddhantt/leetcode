/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0)
            return ans;
        if (nums.front() == 0 && nums.back() == 0)
            return {{0, 0, 0}};
        set<multiset<int>> st;
        int l = 0, m = 1, r = nums.size() - 1;
        while (nums[l] <= 0)
        {
            m = l + 1;
            r = nums.size() - 1;
            int s = nums[l] + nums[m];
            while (s <= 0)
            {
                while (r > m && (nums[r] + s) >= 0)
                {
                    if (s + nums[r] == 0 && st.find({nums[l], nums[m], nums[r]}) == st.end())
                    {
                        ans.push_back({nums[l], nums[m], nums[r]});
                        st.insert({nums[l], nums[m], nums[r]});
                        break;
                    }
                    r--;
                }
                m++;
                if (m > nums.size() - 1)
                    break;
                s = nums[l] + nums[m];
            }
            l++;
            if (l > nums.size() - 2)
                break;
        }
        return ans;
    }
};
// @lc code=end
