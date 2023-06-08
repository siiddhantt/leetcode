/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		priority_queue<pair<int, int>> pq;
		pq.push({nums[n - 1], n - 1});
		for (int i = n - 2; i >= 0; i--) {
			if (pq.top().first <= nums[i]) {
				pq.push({nums[i], i});
				cout << pq.top().first << endl;
			}
			else {
				pair<int, int> tmp;
				while (pq.top().first > nums[i] && !pq.empty()) {
					tmp = pq.top();
					pq.pop();
				}
				int val = nums[i];
				nums[i] = tmp.first;
				nums[tmp.second] = val;
				sort(nums.begin() + i + 1, nums.end());
				return;
			}
		}
		sort(nums.begin(), nums.end());
	}
};
// @lc code=end

