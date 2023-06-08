/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
	void setZeroes(vector<vector<int>>& mat) {
		unordered_map<int, int> mr, mc;
		int m = mat.size(), n = mat[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 0) {
					mr[i]++;
					mc[j]++;
				}
			}
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (mr[i] > 0 || mc[j] > 0)
					mat[i][j] = 0;
	}
};
// @lc code=end
