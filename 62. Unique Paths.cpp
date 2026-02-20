// memoisation

class Solution
{
public:
    int func(int startRow, int startCol, int endRow, int endCol, vector<vector<int>> &dp)
    {
        if (startRow == endRow - 1 && startCol == endCol - 1)
            return 1;

        if (dp[startRow][startCol] != -1)
            return dp[startRow][startCol];

        int right = 0, down = 0;

        if (startRow + 1 <= endRow)
            down = func(startRow + 1, startCol, endRow, endCol, dp);
        if (startCol + 1 <= endCol)
            right = func(startRow, startCol + 1, endRow, endCol, dp);

        return dp[startRow][startCol] = down + right;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return func(0, 0, m, n, dp);
    }
};