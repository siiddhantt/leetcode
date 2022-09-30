/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution
{
public:
    bool bsearch(vector<int> &arr, int t)
    {
        int l = 0, r = (arr.size() - 1);
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (arr[mid] == t)
            {
                return true;
            }
            else if (t < arr[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
    int findKthPositive(vector<int> &arr, int k)
    {
        int cou = 0;
        for (int i = 1; i <= 2000; i++)
        {
            if (bsearch(arr, i) == false)
            {
                cou++;
                if (cou == k)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
