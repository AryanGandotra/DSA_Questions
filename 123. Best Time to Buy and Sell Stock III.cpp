// tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        dp[n][0][0] = dp[n][0][1] = dp[n][0][2] = dp[n][1][0] = dp[n][1][1] =
            dp[n][1][2] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k >= 0; k--)
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

// memoisation
class Solution
{
public:
    long func(int index, int canBuy, vector<int> &prices, vector<vector<vector<int>>> &dp, int transactions)
    {
        if (index == prices.size() || transactions == 2)
            return 0;

        if (dp[index][canBuy][transactions] != -1)
            return dp[index][canBuy][transactions];

        long profit = 0;

        if (canBuy == 1)
            profit = max((-prices[index] + func(index + 1, 0, prices, dp, transactions)), func(index + 1, 1, prices, dp, transactions));
        else
        {
            profit = max((prices[index] + func(index + 1, 1, prices, dp, transactions + 1)), func(index + 1, 0, prices, dp, transactions));
        }

        return dp[index][canBuy][transactions] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int canBuy = 1, index = 0, transactions = 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return func(index, canBuy, prices, dp, transactions);
    }
};