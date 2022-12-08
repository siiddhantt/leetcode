/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.length();
        if (n == 1)
            return "";
        string ans = palindrome;
        unordered_map<char, int> m;
        for (auto i : ans)
        {
            m[i] += 1;
        }
        if (m['a'] == n - 1)
        {
            ans[n - 1] = 'b';
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            if (ans[i] != 'a')
            {
                ans[i] = 'a';
                break;
            }
        }
        if (ans == palindrome)
            ans[n - 1] = 'b';
        return ans;
    }
};
// @lc code=end
