class Solution
{
public:
    int maxProfit(int maxTrans, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(maxTrans + 1, 0)));

        dp[n][0][0] = dp[n][0][1] = dp[n][0][maxTrans] = dp[n][1][0] = dp[n][1][1] =
            dp[n][1][maxTrans] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = maxTrans - 1; k >= 0; k--)
                {
                    long profit = 0;
                    if (j == 1)
                        profit = max((-prices[i] + dp[i + 1][0][k]), dp[i + 1][1][k]);
                    else
                        profit = max((prices[i] + dp[i + 1][1][k + 1]), dp[i + 1][0][k]);

                    dp[i][j][k] = profit;
                }
            }
        }

        return dp[0][1][0];
    }
};