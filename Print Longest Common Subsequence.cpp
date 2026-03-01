#include <algorithm>

string findLCS(int n, int m, string &s1, string &s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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

    int i = n, j = m;
    int index = dp[n][m] - 1;
    string s(dp[n][m], '0');

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s[index] = s1[i - 1];
            index--;
            i--;
            j--;
        }
        else
        {
            int left = dp[i][j - 1], up = dp[i - 1][j];
            if (left > up)
                j = j - 1;
            else
                i = i - 1;
        }
    }

    return s;
}