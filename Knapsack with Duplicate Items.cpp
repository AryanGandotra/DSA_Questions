// memoisation 
class Solution
{
public:
    int func(int index, vector<int> &val, vector<int> &wt, int capacity, vector<vector<int>> &dp)
    {
        // base case
        if (index == 0)
        {
            if (wt[0] <= capacity)
                return (capacity / wt[0]) * val[0];
            return 0;
        }

        if (dp[index][capacity] != -1)
            return dp[index][capacity];

        // pick
        int pick = INT_MIN;
        if (wt[index] <= capacity)
            pick = val[index] + func(index, val, wt, capacity - wt[index], dp);
        // not pick
        int notpick = func(index - 1, val, wt, capacity, dp);

        return dp[index][capacity] = max(pick, notpick);
    }
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return func(n - 1, val, wt, capacity, dp);
    }
};