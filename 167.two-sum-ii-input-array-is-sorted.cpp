/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    int bsearch(vector<int> &arr, int l, int r, int t)
    {
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (arr[mid] == t)
            {
                return mid;
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
        return -1;
    }
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            int curr = numbers[i];
            int diff = target - curr;
            int pos = bsearch(numbers, i + 1, numbers.size() - 1, diff);
            if (pos != -1)
            {
                result.push_back(i + 1);
                result.push_back(pos + 1);
                return result;
            }
        }
        return result;
    }
};
// @lc code=end
