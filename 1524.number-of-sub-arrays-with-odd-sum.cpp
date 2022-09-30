/*
 * @lc app=leetcode id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 */

// @lc code=start
class Solution
{
public:
    long long numOfSubarrays(vector<int> &arr)
    {
        long long n = arr.size();
        long long sum = 0, cou = 0;
        const unsigned int M = 1000000007;
        unordered_map<long long, long long> m;
        m[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            sum %= 2;
            cou += m[sum];
            m[sum]++;
        }
        return ((n * (n + 1) / 2) - cou) % M;
    }
};
// @lc code=end
