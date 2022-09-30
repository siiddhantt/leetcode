/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, string> m;
        m[1] = 'I', m[5] = 'V', m[10] = 'X', m[50] = 'L', m[100] = 'C', m[500] = 'D', m[1000] = 'M', m[4] = 'IV', m[9] = 'IX', m[40] = 'XL', m[90] = 'XC', m[400] = 'CD', m[900] = 'CM';
        int quo, rem, dvsr = 1000;
        int tmp = num;
        string res = '';
        do
        {
            quo = tmp / dvsr;
            rem = tmp % dvsr;
            res += (m[dvsr] * quo);
            tmp = rem;
        } while (rem > 0);
    }
};
// @lc code=end
