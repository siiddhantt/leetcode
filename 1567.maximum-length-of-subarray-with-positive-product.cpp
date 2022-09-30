/*
 * @lc app=leetcode id=1567 lang=cpp
 *
 * [1567] Maximum Length of Subarray With Positive Product
 */

// @lc code=start
class Solution
{
public:
    int maxLenFwd(vector<int> &vec)
    {
        int ccou = 0, cpro = 1;
        int fcou = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] != 0)
            {
                cpro *= (vec[i] / abs(vec[i]));
                ccou++;
            }
            else {
                cpro *= vec[i];
                ccou++;
            }
            if (cpro == 0)
            {
                cpro = 1;
                ccou = 0;
            }
            if (cpro > 0 && ccou > fcou)
            {
                fcou = ccou;
            }
        }
        return fcou;
    }
    int maxLenBck(vector<int> &vec)
    {
        int ccou = 0, cpro = 1;
        int fcou = 0;
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            if (vec[i] != 0)
            {
                cpro *= (vec[i] / abs(vec[i]));
                ccou++;
            }
            else {
                cpro *= vec[i];
                ccou++;
            }
            if (cpro == 0)
            {
                cpro = 1;
                ccou = 0;
            }
            if (cpro > 0 && ccou > fcou)
            {
                fcou = ccou;
            }
        }
        return fcou;
    }
    int getMaxLen(vector<int> &nums)
    {
        return max(maxLenFwd(nums), maxLenBck(nums));
    }
};
// @lc code=end
