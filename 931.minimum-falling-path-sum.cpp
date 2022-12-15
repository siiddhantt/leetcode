/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution
{
public:
    map<vector<int>, int> m;
    void cal(vector<vector<int>> &matrix, int i)
    {
        int n = matrix.size();
        int delc[] = {-1, 0, 1};
        for (int j = 0; j < n; j++)
        {
            int currmin = INT_MAX;
            for (int k = 0; k < 3; k++)
            {
                int newr = i + 1, newc = j + delc[k];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n)
                {
                    vector<int> tmp = {newr, newc};
                    currmin = min(currmin, matrix[i][j] + m[tmp]);
                }
            }
            m[{i, j}] = currmin;
            if (i == n - 1)
                m[{i, j}] = matrix[i][j];
        }
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), ans = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            cal(matrix, i);
        }
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, m[{0, i}]);
        }
        return ans;
    }
};
// @lc code=end
