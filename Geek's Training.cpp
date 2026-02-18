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