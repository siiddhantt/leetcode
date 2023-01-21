class Solution
{
public:
    set<vector<int>> st;
    vector<vector<int>> ans;
    void rec(int i, vector<int> &nums, vector<int> &vec)
    {
        if (i >= nums.size())
        {
            if (vec.size() >= 2)
                st.insert(vec);
            return;
        }
        if (vec.size() != 0)
        {
            if (nums[i] >= vec.back())
            {
                vec.push_back(nums[i]);
                rec(i + 1, nums, vec);
                vec.pop_back();
            }
            rec(i + 1, nums, vec);
        }
        else
        {
            vec.push_back(nums[i]);
            rec(i + 1, nums, vec);
            vec.pop_back();
            rec(i + 1, nums, vec);
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> vec;
        rec(0, nums, vec);
        for (auto it : st)
            ans.push_back(it);
        return ans;
    }
};