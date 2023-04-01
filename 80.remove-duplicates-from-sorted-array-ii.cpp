/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int cpos = 0, curr = nums[0], ccou = 1;
        for (int i = 1; i < n; i++)
        {
            if (curr == nums[i])
            {
                if (ccou < 2)
                    ccou++;
                continue;
            }
            for (int j = cpos; j < (cpos + ccou); j++)
                nums[j] = curr;
            cpos += ccou;
            if (curr != nums[i])
            {
                curr = nums[i];
                ccou = 1;
            }
        }
        for (int j = cpos; j < (cpos + ccou); j++)
            nums[j] = curr;
        return cpos + ccou;
    }
};
// @lc code=end
