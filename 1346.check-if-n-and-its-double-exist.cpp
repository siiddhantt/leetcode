/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]] += 1;
        }
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == 0)
            {
                if ((*m.find(0)).second > 1)
                {
                    return true;
                }
                else
                {
                    m.erase(0);
                }
            }
            if (arr[j] % 2 == 0)
            {
                int q = arr[j] / 2;
                if (m.find(q) != m.end())
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
