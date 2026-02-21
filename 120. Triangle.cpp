// tabualation
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size(), n = triangle[m - 1].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                if (i == m - 1)
                    dp[i][j] = triangle[i][j];

                else
                {
                    int down = triangle[i][j] + dp[i + 1][j];
                    int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                    dp[i][j] = min(down, diagonal);
                }
            }
        }

        return dp[0][0];
    }
};