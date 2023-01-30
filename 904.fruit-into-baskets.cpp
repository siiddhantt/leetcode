/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> m;
        int n = fruits.size(), l = 0, r = 0, ans = 0;
        while (r < n)
        {
            if (m.size() > 2)
            {
                if (m[fruits[l]] == 1)
                    m.erase(fruits[l++]);
                else
                    m[fruits[l++]]--;
                continue;
            }
            m[fruits[r++]]++;
            if (m.size() <= 2)
                ans = max(ans, r - l);
        }
        return ans;
    }
};
// @lc code=end
