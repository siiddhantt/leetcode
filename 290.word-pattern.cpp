/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> vec;
        set<string> st;
        map<char, string> m;
        string w;
        stringstream iss(s);
        while (iss >> w)
            vec.push_back(w);
        if (vec.size() != pattern.size())
            return false;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (m.find(pattern[i]) == m.end())
            {
                if (st.find(vec[i]) != st.end())
                    return false;
                m[pattern[i]] = vec[i];
                st.insert(vec[i]);
            }
            else if (m[pattern[i]] != vec[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
