/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

// @lc code=start
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int cou = 0;
        int flg = 0;
        for (auto &it1 : arr1)
        {
            for (auto &it2 : arr2)
            {
                int diff = abs(it1 - it2);
                if (diff <= d)
                {
                    flg = 1;
                    break;
                }
            }
            if (flg == 0)
            {
                cou++;
            }
            else
            {
                flg = 0;
                continue;
            }
        }
        return cou;
    }
};
// @lc code=end
