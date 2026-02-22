// memoisation

class Solution
{
public:
    int getMaxCherryCount(int currRow, int rb1Col, int rb2Col,
                          vector<vector<int>> &grid, int rows, int cols, vector<vector<vector<int>>> &dp)
    {
        if (currRow == rows)
            return 0;

        if (rb1Col < 0 || rb1Col >= cols || rb2Col < 0 || rb2Col >= cols)
            return -1e8;

        if (currRow == rows - 1)
        {
            if (rb1Col == rb2Col)
                return grid[currRow][rb1Col];
            else
                return grid[currRow][rb1Col] + grid[currRow][rb2Col];
        }

        if (dp[currRow][rb1Col][rb2Col] != -1)
            return dp[currRow][rb1Col][rb2Col];

        int result = -1e8;

        for (int delta1 = -1; delta1 <= 1; delta1++)
        {
            for (int delta2 = -1; delta2 <= 1; delta2++)
            {
                if (rb1Col == rb2Col)
                    result =
                        max(result, grid[currRow][rb1Col] +
                                        getMaxCherryCount(
                                            currRow + 1, rb1Col + delta1,
                                            rb2Col + delta2, grid, rows, cols, dp));
                else
                {
                    result = max(result,
                                 grid[currRow][rb1Col] + grid[currRow][rb2Col] +
                                     getMaxCherryCount(
                                         currRow + 1, rb1Col + delta1,
                                         rb2Col + delta2, grid, rows, cols, dp));
                }
            }
        }

        return dp[currRow][rb1Col][rb2Col] = result;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return getMaxCherryCount(0, 0, n - 1, grid, m, n, dp);
    }
};