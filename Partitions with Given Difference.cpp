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
    int countPartitions(vector<int> &arr, int diff)
    {
        int total = 0, n = arr.size();

        for (int i = 0; i < n; i++)
            total += arr[i];

        if ((diff + total) % 2 == 1)
            return 0;

        int s1 = (diff + total) / 2;
        vector<vector<int>> dp(n, vector(s1 + 1, -1));
        return getCount(n - 1, arr, s1, dp);
    }
};