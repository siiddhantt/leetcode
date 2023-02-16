/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution
{
public:
    int pos = 0;
    string decodeString(string s)
    {
        int len = s.size();
        string ans = "";
        while (pos < len)
        {
            int count = 0;
            string substr = "";
            if (s[pos] == ']')
            {
                pos++;
                return ans;
            }
            while (pos < len && '0' <= s[pos] && s[pos] <= '9')
                count = count * 10 + s[pos++] - '0';
            if (s[pos] == '[')
            {
                pos++;
                substr = decodeString(s);
            }
            while (count--)
                ans += substr;
            while (pos < len && 'a' <= s[pos] && s[pos] <= 'z')
                ans.push_back(s[pos++]);
        }
        return ans;
    }
};
// @lc code=end
