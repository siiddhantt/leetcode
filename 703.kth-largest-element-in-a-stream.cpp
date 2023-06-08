/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest
{
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (auto it : nums)
            pq.push(it);
    }

    int add(int val)
    {
        pq.push(val);
        while (pq.size() > K)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
