// tabulation + Space optimisation

class Solution
{
public:
    int maximumPath(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();

        vector<int> temp(n, 0);

        for (int j = 0; j < n; j++)
            temp[j] = mat[0][j];

        for (int i = 1; i < m; i++)
        {
            vector<int> dp(n, 0);
            for (int j = 0; j < n; j++)
            {

                int up = INT_MIN, upRight = INT_MIN, upLeft = INT_MIN;

                up = mat[i][j] + temp[j];

                if (j < n - 1)
                    upRight = mat[i][j] + temp[j + 1];
                if (j > 0)
                    upLeft = mat[i][j] + temp[j - 1];

                dp[j] = max(up, max(upRight, upLeft));
            }
            temp = dp;
        }

        int result = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            result = max(result, temp[i]);
        }
        return result;
    }
};

// tabulation

class Solution
{
public:
    int maximumPath(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
            dp[0][j] = mat[0][j];

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int up = INT_MIN, upRight = INT_MIN, upLeft = INT_MIN;

                up = mat[i][j] + dp[i - 1][j];

                if (j < n - 1)
                    upRight = mat[i][j] + dp[i - 1][j + 1];
                if (j > 0)
                    upLeft = mat[i][j] + dp[i - 1][j - 1];

                dp[i][j] = max(up, max(upRight, upLeft));
            }
        }

        int result = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            result = max(result, dp[m - 1][i]);
        }
        return result;
    }
};

// memoisation

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