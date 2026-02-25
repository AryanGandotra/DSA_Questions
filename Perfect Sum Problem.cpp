class Solution
{
public:
    int getCount(int index, vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target == 0)
            {
                if (arr[0] == 0)
                    return 2;
                return 1;
            }
            return arr[index] == target;
        }

        if (dp[index][target] != -1)
            return dp[index][target];

        // not pick
        int notpick = getCount(index - 1, arr, target, dp);

        // pick
        int pick = 0;
        if (arr[index] <= target)
            pick = getCount(index - 1, arr, target - arr[index], dp);

        return dp[index][target] = (pick + notpick);
    }

    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector(target + 1, -1));
        return getCount(n - 1, arr, target, dp);
    }
};