/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        reverse(num.begin(), num.end());
        int n = num.size(), i = 0, c = 0;
        while (k != 0 || c != 0)
        {
            if (i >= n)
                num.push_back(0);
            int t1 = k % 10;
            int t2 = (num[i] + t1 + c) % 10;
            if (num[i] + t1 + c > 9)
                c = 1;
            else
                c = 0;
            num[i] = t2;
            i++;
            k /= 10;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};
// @lc code=end
