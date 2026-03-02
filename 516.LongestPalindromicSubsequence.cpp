class Solution
{
public:
    int lcs(string &s1, string &s2)
    {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[m][n];
    }

    int longestPalindromeSubseq(string s1)
    {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int n = s1.length(), m = s2.length();
        return lcs(s1, s2);
    }
};