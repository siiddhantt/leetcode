/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> m;
        for (auto &it : nums)
        {
            m[it] += 1;
        }
        for (int i = n; i > 0; i--)
        {
            int cou = 0;
            map<int, int>::reverse_iterator it;
            for (it = m.rbegin(); it != m.rend(); ++it)
            {
                if ((*it).first >= i)
                {
                    cou += (*it).second;
                }
            }
            if (cou == i)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
