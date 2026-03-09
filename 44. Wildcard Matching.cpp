class Solution
{
public:
    bool func(int m, int n, string &s, string &p, vector<vector<int>> &dp)
    {
        if (m < 0 && n < 0)
        {
            return true;
        }

        if (n < 0 && m >= 0)
        {
            return false;
        }

        if (m < 0 && n >= 0)
        {
            for (int i = 0; i <= n; i++)
                if (p[i] != '*')
                    return false;

            return true;
        }

        if (dp[m][n] != -1)
            return dp[m][n];

        if (s[m] == p[n] || p[n] == '?')
            return dp[m][n] = func(m - 1, n - 1, s, p, dp);

        if (p[n] == '*')
        {
            return dp[m][n] = (func(m, n - 1, s, p, dp) || func(m - 1, n, s, p, dp));
        }

        return dp[m][n] = false;
    }
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, s, p, dp);
    }
};