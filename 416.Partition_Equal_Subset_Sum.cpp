// memoisation

class Solution
{
public:
    bool subArraySum(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;

        if (index == 0)
            return target == nums[0];

        if (dp[index][target] != -1)
            return dp[index][target];

        // not pick
        bool notPick = subArraySum(index - 1, target, nums, dp);

        // pick
        bool pick = false;

        if (target >= nums[index])
            pick = subArraySum(index - 1, target - nums[index], nums, dp);

        return dp[index][target] = pick || notPick;
    }

    bool canPartition(vector<int> &nums)
    {
        int arraySum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            arraySum += nums[i];

        int target = arraySum / 2;

        vector<vector<int>> dp(n, vector(target + 1, -1));

        if (arraySum % 2 == 1)
            return false;

        return subArraySum(n - 1, target, nums, dp);
    }
};

class Solution
{
public:
    bool dp[201][20001];

    int getSum(vector<int> arr, int n)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    bool isSubsetSum(vector<int> arr, int n, int sum)
    {
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (int j = 1; j <= sum; j++)
        {
            dp[0][j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = getSum(nums, nums.size());

        if (sum % 2 == 1)
            return false;

        return isSubsetSum(nums, nums.size(), sum / 2);
    }
};