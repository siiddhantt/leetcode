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
        int m = matrix.size(), n = matrix[0].size(), ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        for (int r = 0; r < min(m, k); ++r)
            minHeap.push({matrix[r][0], r, 0});
        while (k--)
        {
            auto top = minHeap.top();
            minHeap.pop();
            ans = top[0];
            int r = top[1], c = top[2];
            if (c + 1 < n)
                minHeap.push({matrix[r][c + 1], r, c + 1});
        }
        return ans;
    }
};
// @lc code=end
