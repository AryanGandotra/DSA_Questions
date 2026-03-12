class Solution
{
public:
    long func(int index, int canBuy, vector<int> &prices,
              vector<vector<int>> &dp, int fee)
    {
        if (index >= prices.size())
            return 0;

        if (dp[index][canBuy] != -1)
            return dp[index][canBuy];

        long profit = 0;

        if (canBuy == 1)
            profit = max(
                (-prices[index] + func(index + 1, 0, prices, dp, fee)),
                func(index + 1, 1, prices, dp, fee));
        else
            profit =
                max((prices[index] - fee + func(index + 1, 1, prices, dp, fee)),
                    func(index + 1, 0, prices, dp, fee));

        return dp[index][canBuy] = profit;
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        int canBuy = 1, index = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return func(index, canBuy, prices, dp, fee);
    }
};