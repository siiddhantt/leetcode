/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> generate(int nR) {
		vector<vector<int>> vec;
		vec.push_back({1});
		for (int i = 1; i < nR; i++) {
			vector<int> tmp;
			for (int j = 0; j <= i; j++) {
				if (j == 0)
					tmp.push_back(vec[i - 1].front());
				else if (j == i)
					tmp.push_back(vec[i - 1].back());
				else
					tmp.push_back(vec[i - 1][j - 1] + vec[i - 1][j]);
			}
			vec.push_back(tmp);
		}
		return vec;
	}
};
// @lc code=end
