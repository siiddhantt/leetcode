/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 */

// @lc code=start
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int n = arr.size();
        int sum = 0, cou = 0, l = 0, r = k - 1;
        for (int i = 0; i < k - 1; i++)
        {
            sum += arr[i];
        }
        while (r < n)
        {
            sum += arr[r++];
            int avg = sum / k;
            if (avg >= threshold)
            {
                cou++;
            }
            sum -= arr[l++];
        }
        return cou;
    }
};
// @lc code=end
