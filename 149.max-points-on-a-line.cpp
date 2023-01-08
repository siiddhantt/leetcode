/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        if (points.size() == 1 || points.size() == 2)
            return points.size();
        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> m;
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++)
            {
                double s;
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 != x2)
                {
                    s = (double)(y2 - y1) / (double)(x2 - x1);
                    cout << s << endl;
                    m[s]++;
                }
                else
                    m[s = 100000.0]++;
                ans = max(ans, m[s]);
            }
        }
        return ans + 1;
    }
};
// @lc code=end
