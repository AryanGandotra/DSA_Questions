// tabulation

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                long profit = 0;
                if (j == 1)
                    profit = max((-prices[i] + dp[i + 1][0]), dp[i + 1][1]);
                else
                    profit = max((prices[i] + dp[i + 1][1]), dp[i + 1][0]);

                dp[i][j] = profit;
            }
        }

        return dp[0][1];
    }
};

// memoisation
class Solution
{
public:
    long func(int index, int canBuy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (dp[index][canBuy] != -1)
            return dp[index][canBuy];

        long profit = 0;

        if (canBuy == 1)
            profit = max((-prices[index] + func(index + 1, 0, prices, dp)), func(index + 1, 1, prices, dp));
        else
            profit = max((prices[index] + func(index + 1, 1, prices, dp)), func(index + 1, 0, prices, dp));

        return dp[index][canBuy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int canBuy = 1, index = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return func(index, canBuy, prices, dp);
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                ans += (prices[i] - prices[i - 1]);
        }
        return ans;
    }
};