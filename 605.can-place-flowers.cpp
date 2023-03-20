/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int num)
    {
        int cou = 0, n = flowerbed.size();
        if (n == 1 && flowerbed[0] == 0)
            return num <= 1 ? true : false;
        else if (n == 1 && flowerbed[0] == 1)
            return num == 0 ? true : false;
        else if (n == 2 && flowerbed[0] == 0 && flowerbed[1] == 0)
            return num <= 1 ? true : false;
        for (int i = 0; i < n; i++)
        {
            if (flowerbed[i] == 0 && i > 0 && i < n - 1)
            {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    cou++;
                    i++;
                }
            }
            else if (flowerbed[i] == 0 && (i == 0 || i == n - 1))
            {
                if (i == 0 && flowerbed[i + 1] == 0)
                {
                    cou++;
                    i++;
                }
                else if (i == n - 1 && flowerbed[i - 1] == 0)
                    cou++;
            }
        }
        cout << cou;
        if (cou >= num)
            return true;
        return false;
    }
};
// @lc code=end
