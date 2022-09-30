/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        multimap<int, int> diff;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            diff.insert({abs(arr[i] - x), arr[i]});
        }
        int c = 1;
        for (auto it : diff)
        {
            if (c > k)
                break;
            ans.push_back(it.second);
            c++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
