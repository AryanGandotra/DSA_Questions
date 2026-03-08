// tabulation
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    // insert
                    int insert = 1 + dp[i][j - 1];
                    // replace
                    int replace = 1 + dp[i - 1][j - 1];
                    // delete
                    int del = 1 + dp[i - 1][j];

                    dp[i][j] = min(insert, min(replace, del));
                }
            }
        }

        return dp[m][n];
    }
};

// memeoisation

class Solution
{
public:
    int func(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = func(i - 1, j - 1, word1, word2, dp);
        else
        {
            // insert
            int insert = 1 + func(i, j - 1, word1, word2, dp);
            // replace
            int replace = 1 + func(i - 1, j - 1, word1, word2, dp);
            // delete
            int del = 1 + func(i - 1, j, word1, word2, dp);

            return dp[i][j] = min(insert, min(replace, del));
        }
    }
    int minDistance(string word1, string word2)
    {
        int i = word1.length(), j = word2.length();
        vector<vector<int>> dp(i, vector<int>(j, -1));
        return func(i - 1, j - 1, word1, word2, dp);
    }
};