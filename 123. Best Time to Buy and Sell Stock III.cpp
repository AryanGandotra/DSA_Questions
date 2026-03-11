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