/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        int l = 0, r = n - 1, cou = 0;
        sort(people.begin(), people.end());
        while (l <= r)
        {
            int lval = people[l], rval = people[r];
            if (lval + rval <= limit)
            {
                l++;
                r--;
            }
            else
                r--;
            cou++;
        }
        return cou;
    }
};
// @lc code=end
