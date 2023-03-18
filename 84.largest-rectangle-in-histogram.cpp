/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> stk;
        int n = heights.size(), ans = INT_MIN, cou;
        for (int i = 0; i <= n; i++)
        {
            while (!stk.empty() && (i == n || heights[stk.top()] >= heights[i]))
            {
                int t = stk.top(), pre;
                stk.pop();
                pre = !stk.empty() ? stk.top() : -1;
                cou = i - pre - 1;
                ans = max(ans, heights[t] * cou);
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end
