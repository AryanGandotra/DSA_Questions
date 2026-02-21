// tabulation

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[0][0] = grid[0][0];

                else
                {
                    int up = INT_MAX, left = INT_MAX;

                    if (i - 1 >= 0)
                        up = grid[i][j] + dp[i - 1][j];
                    if (j - 1 >= 0)
                        left = grid[i][j] + dp[i][j - 1];

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

// memoisation

class Solution
{
public:
    int getMinPathSum(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
            return grid[0][0];

        if (dp[m][n] != -1)
            return dp[m][n];

        int up = INT_MAX, left = INT_MAX;

        if (m - 1 >= 0)
            up = grid[m][n] + getMinPathSum(m - 1, n, grid, dp);
        if (n - 1 >= 0)
            left = grid[m][n] + getMinPathSum(m, n - 1, grid, dp);

        return dp[m][n] = min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return getMinPathSum(m - 1, n - 1, grid, dp);
    }
}; 

// recursive - will fail in LC submission

class Solution
{
public:
    int getMinPathSum(int m, int n, vector<vector<int>> &grid)
    {
        if (m == 0 && n == 0)
            return grid[0][0];

        int up = INT_MAX, left = INT_MAX;

        if (m - 1 >= 0)
            up = grid[m][n] + getMinPathSum(m - 1, n, grid);
        if (n - 1 >= 0)
            left = grid[m][n] + getMinPathSum(m, n - 1, grid);

        return min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        return getMinPathSum(m - 1, n - 1, grid);
    }
};