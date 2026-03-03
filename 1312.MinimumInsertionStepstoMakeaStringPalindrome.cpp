// memoisation
class Solution
{
public:
    int lcs(string s1, string s2)
    {
        int n = s1.length(), m = n;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }

    int minInsertions(string s)
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int lcsN = lcs(s, s2);
        return s.length() - lcsN;
    }
};

class Solution
{
public:
    int dp[501][501];

    int lcs(string s1, string s2, int m, int n)
    {
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
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    pair<int, int> minInsertionDeletions(string s1, string s2, int m, int n)
    {
        int ins, del;

        ins = n - lcs(s1, s2, m, n);
        del = m - lcs(s1, s2, m, n);

        return {ins, del};
    }
    string reverseString(string s)
    {
        string reverseStr = "";

        for (int i = s.length() - 1; i >= 0; i--)
        {
            reverseStr += s[i];
        }

        return reverseStr;
    }

    int minInsertions(string s)
    {
        int m = s.length();
        return minInsertionDeletions(s, reverseString(s), m, m).first;
    }
};