/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution
{
public:
    bool searchChar(vector<char> &tmp, char i, int strt)
    {
        for (int j = strt; j < tmp.size(); j++)
        {
            if (tmp[j] == i)
            {
                return true;
            }
        }
        return false;
    }

    bool isIsomorphic(string s, string t)
    {
        vector<char> lst;
        for (int i = 0; i < s.length(); i++)
        {
            if (searchChar(lst, s.at(i), 0))
            {
                lst.push_back(s.at(i));
            }
            else
            {
                continue;
            }
        }
        int pos = 0;
        for (int i = 0; i < t.length(); i++)
        {
            
        }
        // vector<char>::iterator iter;
        // for (iter = lst.begin(); iter != lst.end(); ++iter)
        // {
        //     cout << *iter << "  ";
        // }
        return true;
    }
};
// @lc code=end
