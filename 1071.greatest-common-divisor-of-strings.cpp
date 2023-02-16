/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        int n1 = str1.size(), n2 = str2.size();
        int l = gcd(n1, n2);
        return str1.substr(0, l);
    }
};
// @lc code=end
