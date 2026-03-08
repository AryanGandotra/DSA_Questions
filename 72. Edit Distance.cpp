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