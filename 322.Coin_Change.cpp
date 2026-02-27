// tabulation

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
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

// memoisation
class Solution
{
public:
    int func(int index, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int pick = 1e8;
        if (coins[index] <= amount)
            pick = 1 + func(index, coins, amount - coins[index], dp);

        int notpick = func(index - 1, coins, amount, dp);

        return dp[index][amount] = min(pick, notpick);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        if (amount <= 0)
            return 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(n - 1, coins, amount, dp);
        if (ans >= 1e8)
            return -1;
        return ans;
    }
};

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= amount; j++)
        {
            dp[0][j] = INT_MAX - 1;
        }

        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
            {
                dp[1][j] = j / coins[0];
            }
            else
            {
                dp[1][j] = INT_MAX - 1;
            }
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    }
};