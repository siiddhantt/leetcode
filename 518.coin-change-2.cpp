class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int size = coins.size(), x = size + 1, y = amount + 1;
        vector<vector<int>> dp(x, vector<int>(y, 0));
        for (int i = 0; i < x; i++)
            dp[i][0] = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = 1; j < y; j++)
            {
                if (coins[i] <= j)
                    dp[i][j] = dp[i][j - coins[i]] + dp[i + 1][j];
                else
                    dp[i][j] = dp[i + 1][j];
            }
        }
        return dp[0][amount];
    }
};