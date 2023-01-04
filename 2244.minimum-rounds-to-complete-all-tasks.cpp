/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
 */

// @lc code=start
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int ans = 0;
        map<int, int> m;
        for (auto it : tasks)
            m[it]++;
        for (auto it : m)
        {
            int cou = 0;
            if (it.second == 1)
                return -1;
            else if (it.second % 3 == 1)
            {
                int q = it.second / 3;
                cou += q - 1;
                cou += (it.second - (q - 1) * 3) / 2;
            }
            else if (it.second % 3 == 2)
            {
                int q = it.second / 3;
                cou += q;
                cou += (it.second - q * 3) / 2;
            }
            else
                cou += it.second / 3;
            ans += cou;
        }
        return ans;
    }
};
// @lc code=end
