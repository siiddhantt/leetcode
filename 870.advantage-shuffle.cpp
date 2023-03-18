/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), p1 = 0, p2 = 0, cou = 0;
        vector<int> ans(n, -1), rem;
        vector<pair<int, int>> n2;
        for (int i = 0; i < n; i++)
            n2.push_back({nums2[i], i});
        sort(n2.begin(), n2.end());
        sort(nums1.begin(), nums1.end());
        while (p2 < n && p1 < n)
        {
            if (nums1[p1] <= n2[p2].first)
                rem.push_back(nums1[p1++]);
            else
            {
                cou++;
                ans[n2[p2++].second] = nums1[p1++];
            }
        }
        for (int i = 0; i < n; i++)
            if (ans[i] == -1)
            {
                ans[i] = rem[0];
                rem.erase(rem.begin());
            }
        return ans;
    }
};
// @lc code=end
