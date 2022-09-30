/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        multimap<int, int> m;
        vector<int> fres;
        for (int i = 0; i < mat.size(); i++)
        {
            int l = 0, r = mat[0].size() - 1, res = -1;
            while (l <= r)
            {
                int mid = l + ((r - l) / 2);
                if (mat[i][mid] == 1)
                {
                    res = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            m.insert(pair<int, int>(res + 1, i));
        }
        int cou = 0;
        for (auto &it : m)
        {
            cou++;
            fres.push_back((it.second));
            if (cou >= k)
            {
                break;
            }
        }
        return fres;
    }
};
// @lc code=end
