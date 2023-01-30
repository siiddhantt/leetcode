/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
class SummaryRanges
{
public:
    set<int> st;
    SummaryRanges() {}

    void addNum(int value)
    {
        st.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        if (st.empty())
            return {};
        vector<vector<int>> ans;
        int l = -1, r = -1;
        for (auto it : st)
        {
            if (l < 0)
                l = it, r = it;
            else if (it == r + 1)
                r = it;
            else
            {
                ans.push_back({l, r});
                l = it, r = it;
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end
