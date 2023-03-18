/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution
{
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int> &arr)
    {
        long long s = 0, cou;
        int n = arr.size();
        stack<int> stk;
        for (int i = 0; i <= n; i++)
        {
            if (stk.empty())
            {
                stk.push(i);
                continue;
            }
            while (!stk.empty() && (i == n || arr[stk.top()] >= arr[i]))
            {
                int t = stk.top(), pre;
                stk.pop();
                if (!stk.empty())
                    pre = stk.top();
                else
                    pre = -1;
                cou = (t - pre) * (i - t) % mod;
                s += (arr[t] * cou) % mod;
                s %= mod;
            }
            stk.push(i);
        }
        return s;
    }
};
// @lc code=end
