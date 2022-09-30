/*
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring
 */

// @lc code=start
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int n = s.length(), m = part.length();
        vector<char> vec;
        for (int i = 0; i < n; i++)
        {
            vec.push_back(s[i]);
            if (vec.size() >= m)
            {
                string tmp = "";
                for (int j = vec.size() - m; j < vec.size(); j++)
                {
                    tmp += vec[j];
                }
                if (tmp == part)
                {
                    for (int k = 0; k < m; k++)
                    {
                        vec.pop_back();
                    }
                }
            }
        }
        string str(vec.begin(), vec.end());
        return str;
    }
};
// @lc code=end
