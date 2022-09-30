/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 0;
        long long r = n-1;
        long long bad = n;
        while (l <= r)
        {
            long m = l + (r - l) / 2;

            if (isBadVersion(m+1))
            {
                if((m+1)<=bad){
                    bad = m+1;
                }

                r = m - 1;
            }

            else
            {
                l = m + 1;                
            }
            
        }

        return bad;
    }
};
// @lc code=end

