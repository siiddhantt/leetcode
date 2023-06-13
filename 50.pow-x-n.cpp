/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		else if (n < 0) {
			x = 1 / x;
			n = abs(n);
		}
		if (n % 2 == 0)
			x = myPow(x * x, n / 2);
		else
			x *= myPow(x, n - 1);
		return x;
	}
};
// @lc code=end

