/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        int l = 0, r = n - 1, mid;
        if (target >= letters[n - 1])
        {
            return letters[0];
        }
        else
        {
            while (l <= r)
            {
                mid = l + ((r - l) / 2);
                if (target == letters[mid])
                {
                    if (letters[mid + 1] != target)
                    {
                        return letters[mid + 1];
                    }
                    else
                    {
                        int pos = mid + 1;
                        while (letters[pos] == target)
                        {
                            pos++;
                        }
                        return letters[pos];
                    }
                }
                else if (target < letters[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return letters[l];
    }
};
// @lc code=end
