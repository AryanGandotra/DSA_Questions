// tabulation
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int j = wt[0]; j <= W; j++)
            dp[0][j] = val[0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int pick = INT_MIN;
                if (wt[i] <= j)
                {
                    pick = val[i] + dp[i - 1][j - wt[i]];
                }
                int notpick = dp[i - 1][j];
                dp[i][j] = max(pick, notpick);
            }
        }
        return dp[n - 1][W];
    }
};

// memoisation
class Solution
{
public:
    int func(int index, vector<int> &val, vector<int> &wt, int W, vector<vector<int>> &dp)
    {
        if (W <= 0 || index < 0)
            return 0;

        if (dp[index][W] != -1)
            return dp[index][W];

        int pick = INT_MIN;
        if (wt[index] <= W)
        {
            pick = val[index] + func(index - 1, val, wt, W - wt[index], dp);
        }
        int notpick = func(index - 1, val, wt, W, dp);

        return dp[index][W] = max(pick, notpick);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return func(n - 1, val, wt, W, dp);
    }
};