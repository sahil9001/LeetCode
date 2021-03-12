class Solution
{
public:
    int calc(vector<int> &coins, int amount)
    {
        int dp[coins.size() + 1][amount + 1];
        for (int i = 0; i < coins.size() + 1; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i < amount + 1; i++)
        {
            dp[0][i] = INT_MAX - 1;
        }
        dp[0][0] = 0;
        for (int i = 1; i < coins.size() + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (j >= coins[i - 1])
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[coins.size()][amount] == INT_MAX - 1)
            return -1;
        return dp[coins.size()][amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        return calc(coins, amount);
    }
};