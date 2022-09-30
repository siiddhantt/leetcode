/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        priority_queue<int> maxh;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int curr = matrix[i][j];
                maxh.push(curr);
                if (maxh.size() > k)
                {
                    maxh.pop();
                }
            }
        }
        return maxh.top();
    }
};
// @lc code=end
