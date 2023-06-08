/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
	void rotate(vector<vector<int>>& mat) {
		int n = mat.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int tmp = mat[i][j];
				mat[i][j] = mat[j][i];
				mat[j][i] = tmp;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				int tmp = mat[i][j];
				mat[i][j] = mat[i][n - 1 - j];
				mat[i][n - 1 - j] = tmp;
			}
		}
	}
};
// @lc code=end
