/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    typedef pair<int, int> pi;

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        priority_queue<pi, vector<pi>, greater<pi>> minh;
        vector<int> ans;
        for (auto it : nums)
        {
            m[it]++;
        }
        for (auto it : m)
        {
            auto tmp = make_pair(it.second, it.first);
            minh.push(tmp);
            if (minh.size() > k)
                minh.pop();
        }
        for (int i = 0; i < k; i++)
        {
            auto tmp = minh.top();
            minh.pop();
            ans.push_back(tmp.second);
        }
        return ans;
    }
};
// @lc code=end
