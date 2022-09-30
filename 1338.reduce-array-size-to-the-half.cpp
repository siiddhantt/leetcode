/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> m;
        for (auto it : arr)
        {
            m[it] += 1;
        }
        vector<int> vec;
        for (auto it : m)
        {
            vec.push_back(it.second);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        int currs = 0, ans = 0, i = 0;
        while (currs < (n / 2))
        {
            ans++;
            currs += vec[i];
            i++;
        }
        return ans;
    }
};
// @lc code=end
