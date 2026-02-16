class Solution
{
public:
    int getMinEnergy(int n, vector<int> &height, vector<int> &dp)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int oneStep = getMinEnergy(n - 1, height, dp) + abs(height[n] - height[n - 1]);

        int twoStep = INT_MAX;
        if (n > 1)
        {
            twoStep = getMinEnergy(n - 2, height, dp) + abs(height[n] - height[n - 2]);
        }

        return dp[n] = min(oneStep, twoStep);
    }

    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return getMinEnergy(n - 1, height, dp);
    }
};