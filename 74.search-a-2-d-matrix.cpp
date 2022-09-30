/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while ((i >= 0 & i < m) && (j >= 0 && j < n))
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (target < matrix[i][j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};
// @lc code=end
