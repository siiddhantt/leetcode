/*
 * @lc app=leetcode id=1387 lang=cpp
 *
 * [1387] Sort Integers by The Power Value
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> m;
    int cal_pow(int i)
    {
        if (i == 1)
            return 0;
        if (m.find(i) != m.end())
            return m[i];
        int steps;
        if (i % 2 == 0)
            steps = 1 + cal_pow(i / 2);
        else
            steps = 1 + cal_pow((3 * i) + 1);
        return m[i] = steps;
    }
    int getKth(int lo, int hi, int k)
    {
        priority_queue<pair<int, int>> pq;
        for (int i = lo; i <= hi; i++)
        {
            int pow = cal_pow(i);
            pq.push({pow, i});
        }
        for (int i = 0; i < (hi - lo + 1) - k; i++)
            pq.pop();
        return pq.top().second;
    }
};
// @lc code=end
