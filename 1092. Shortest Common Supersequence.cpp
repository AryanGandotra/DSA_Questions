class Solution
{
public:
    string shortestCommonSupersequence(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

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

        int i = m, j = n;
        int size = m + n - dp[m][n];
        int index = size - 1;
        string s(size, '0');

        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                s[index] = s1[i - 1];
                i--;
                j--;
            }
            else
            {
                int left = dp[i][j - 1], up = dp[i - 1][j];
                if (left > up)
                {
                    s[index] = s2[j - 1];
                    j--;
                }
                else
                {
                    s[index] = s1[i - 1];
                    i--;
                }
            }
            index--;
        }

        while (i > 0)
        {
            s[index] = s1[i - 1];
            i--;
            index--;
        }

        while (j > 0)
        {
            s[index] = s2[j - 1];
            j--;
            index--;
        }

        return s;
    }
};