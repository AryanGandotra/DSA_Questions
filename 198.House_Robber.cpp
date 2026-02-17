// tabulation + Space optimization

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int prev2 = 0, prev = nums[0];

        for (int i = 2; i <= n; i++)
        {
            int pick = nums[i - 1] + prev2;
            int notpick = prev;
            int curr = max(pick, notpick);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

// tabulation

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            int pick = nums[i - 1] + dp[i - 2];
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }

        return dp[n];
    }
};

// memoization

class Solution
{
public:
    int helper(int index, vector<int> &nums, vector<int> &dp)
    {
        if (index == 0)
        {
            return nums[index];
        }
        if (index < 0)
        {
            return 0;
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }

        int pick = nums[index] + helper(index - 2, nums, dp);
        int notpick = helper(index - 1, nums, dp);

        return dp[index] = max(pick, notpick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return helper(n - 1, nums, dp);
    }
};