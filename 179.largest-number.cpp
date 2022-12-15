/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                string s1 = to_string(nums[j]) + to_string(nums[j - 1]);
                string s2 = to_string(nums[j - 1]) + to_string(nums[j]);
                if (s1 > s2)
                {
                    int tmp = nums[j];
                    nums[j] = nums[j - 1];
                    nums[j - 1] = tmp;
                }
            }
        }
        int cou = 0;
        for (auto it : nums)
        {
            ans += to_string(it);
            if (it == 0)
                cou++;
        }
        if (cou == n)
            return "0";
        return ans;
    }
};
// @lc code=end
