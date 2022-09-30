/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxFwd(vector<int> &vec)
    {
        int cpro = 1, fpro = INT_MIN;
        for (int i = 0; i < vec.size(); i++)
        {
            cpro *= vec[i];
            if (cpro > fpro)
            {
                fpro = cpro;
            }
            if (cpro == 0)
            {
                cpro = 1;
            }
        }
        return fpro;
    }
    int maxBck(vector<int> &vec)
    {
        int cpro = 1, fpro = INT_MIN;
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            cpro *= vec[i];
            if (cpro > fpro)
            {
                fpro = cpro;
            }
            if (cpro == 0)
            {
                cpro = 1;
            }
        }
        return fpro;
    }
    int maxProduct(vector<int> &nums)
    {
        return max(maxFwd(nums), maxBck(nums));
    }
};
// @lc code=end
