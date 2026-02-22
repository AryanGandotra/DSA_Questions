// memoisation

// User function Template for C++

class Solution
{
public:
    int getMaxPathSum(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if (row < 0 || col < 0 || col >= mat[0].size())
            return INT_MIN;

        if (row == 0)
            return mat[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        int up = 0, upRight = 0, upLeft = 0;

        up = mat[row][col] + getMaxPathSum(row - 1, col, mat, dp);
        upRight = mat[row][col] + getMaxPathSum(row - 1, col + 1, mat, dp);
        upLeft = mat[row][col] + getMaxPathSum(row - 1, col - 1, mat, dp);

        return dp[row][col] = max(up, max(upRight, upLeft));
    }

    int maximumPath(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int result = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            result = max(result, getMaxPathSum(m - 1, i, mat, dp));
        }
        return result;
    }
};