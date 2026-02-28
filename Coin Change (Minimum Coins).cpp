class Solution
{
public:
    int minCoins(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
            else
                dp[0][j] = 1e9;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int pick = 1e8;
                if (coins[i] <= j)
                    pick = 1 + dp[i][j - coins[i]];

                int notpick = dp[i - 1][j];

                dp[i][j] = min(pick, notpick);
            }
        }

        return dp[n - 1][amount] >= 1e8 ? -1 : dp[n - 1][amount];
    }
};