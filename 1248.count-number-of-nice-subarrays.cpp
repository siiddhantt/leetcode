/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        nums.push_back(0);
        int n = nums.size(), l = 0, r = 0, cou = 0, ans = 0;
        while (l <= r && r < n)
        {
            if (cou == k)
            {
                int i;
                for (i = r; i < n - 1; i++)
                {
                    if (nums[i] % 2 != 0)
                        break;
                }
                ans += (i + 1) - r;
                if (nums[l] % 2 != 0)
                    cou--;
                l++;
            }
            else
            {
                if (nums[r] % 2 != 0)
                    cou++;
                r++;
            }
        }
        return ans;
    }
};
// @lc code=end
