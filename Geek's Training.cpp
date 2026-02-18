// tabulation
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));

        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));

        for (int day = 1; day < n; day++)
        {

            for (int last = 0; last < 4; last++)
            {
                for (int task = 0; task <= 2; task++)
                {
                    if (task != last)
                    {
                        int points = mat[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], points);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};

// memoisation
class Solution
{
public:
    int func(int day, int lastActivity, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxi = 0;

            for (int i = 0; i <= 2; i++)
            {
                if (i != lastActivity)
                {
                    maxi = max(maxi, mat[day][i]);
                }
            }

            return maxi;
        }

        if (dp[day][lastActivity] != -1)
            return dp[day][lastActivity];

        int maxi = 0;

        for (int i = 0; i <= 2; i++)
        {
            if (i != lastActivity)
            {
                int points = mat[day][i] + func(day - 1, i, mat, dp);
                maxi = max(maxi, points);
            }
        }

        return dp[day][lastActivity] = maxi;
    }

    int maximumPoints(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));
        return func(n - 1, 3, mat, dp);
    }
};

// recursive

class Solution
{
public:
    int func(int day, int lastActivity, vector<vector<int>> &mat)
    {
        if (day == 0)
        {
            int maxi = 0;

            for (int i = 0; i <= 2; i++)
            {
                if (i != lastActivity)
                {
                    maxi = max(maxi, mat[day][i]);
                }
            }

            return maxi;
        }

        int maxi = 0;

        for (int i = 0; i <= 2; i++)
        {
            if (i != lastActivity)
            {
                int points = mat[day][i] + func(day - 1, i, mat);
                maxi = max(maxi, points);
            }
        }

        return maxi;
    }

    int maximumPoints(vector<vector<int>> &mat)
    {
        int n = mat.size();
        return func(n - 1, 3, mat);
    }
};