// memoisation
class Solution
{
public:
    int func(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (amount % coins[0] == 0)
                return 1;
            return 0;
        }

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int pick = 0;
        if (coins[index] <= amount)
            pick = func(index, amount - coins[index], coins, dp);

        int notpick = func(index - 1, amount, coins, dp);

        return dp[index][amount] = pick + notpick;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return func(n - 1, amount, coins, dp);
    }
};

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int j = 0; j <= amount; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {

                if (coins[i - 1] <= j)
                {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount];
    }
};