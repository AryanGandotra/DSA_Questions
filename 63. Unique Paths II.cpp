// tabulation
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1)
            return 0;

        for (int currRow = 0; currRow < m; currRow++)
        {
            for (int currCol = 0; currCol < n; currCol++)
            {

                if (currRow >= 0 && currCol >= 0 &&
                    obstacleGrid[currRow][currCol] == 1)
                {
                    dp[currRow][currCol] = 0;
                }
                else if (currRow == 0 && currCol == 0)
                {
                    dp[currRow][currCol] = 1;
                }
                else
                {
                    int up = 0, left = 0;

                    if (currRow - 1 >= 0)
                        up = dp[currRow - 1][currCol];

                    if (currCol - 1 >= 0)
                        left = dp[currRow][currCol - 1];

                    dp[currRow][currCol] = up + left;
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
    int func(int row, int col, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (obstacleGrid[row][col] == 1)
            return 0;

        if (row == 0 && col == 0)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        int up = 0, left = 0;

        if (row - 1 >= 0 && obstacleGrid[row - 1][col] == 0)
            up = func(row - 1, col, obstacleGrid, dp);
        if (col - 1 >= 0 && obstacleGrid[row][col - 1] == 0)
            left = func(row, col - 1, obstacleGrid, dp);

        return dp[row][col] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, obstacleGrid, dp);
    }
};