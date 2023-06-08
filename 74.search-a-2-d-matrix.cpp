/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
	bool bsearch(vector<vector<int>>& mat, int row, int t) {
		int n = mat[0].size();
		int i = 0, j = n - 1;
		while (j - i > 1) {
			int md = i + (j - i) / 2;
			if (mat[row][md] == t)
				return true;
			else if (mat[row][md] > t)
				j = md - 1;
			else
				i = md + 1;
		}
		if (mat[row][i] == t)
			return true;
		if (mat[row][j] == t)
			return true;
		return false;
	}
	bool searchMatrix(vector<vector<int>>& mat, int t) {
		int m = mat.size();
		int i = 0, j = m - 1;
		while (j - i > 1) {
			int md = i + (j - i) / 2;
			if (mat[md][0] > t)
				j = md - 1;
			else
				i = md;
		}
		if (bsearch(mat, i, t))
			return true;
		if (bsearch(mat, j, t))
			return true;
		return false;
	}
};
// @lc code=end
