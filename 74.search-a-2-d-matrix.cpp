/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool bsearch(int i, int j, vector<vector<int>> &vec, int t)
    {
        int l = 0, r = j;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (vec[i][m] == t)
                return true;
            else if (vec[i][m] < t)
                l = m + 1;
            else
                r = m - 1;
        }
        if (vec[i][l] == t || vec[i][r] == t)
            return true;
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while ((i >= 0 && i < m) && (j >= 0 && j < n))
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] >= target)
                return bsearch(i, j, matrix, target);
            else
                i++;
        }
        return false;
    }
};
// @lc code=end
