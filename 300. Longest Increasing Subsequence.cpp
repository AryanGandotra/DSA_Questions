// tabulation
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {

                int notTake = dp[i + 1][prev + 1];

                int take = 0;
                if (prev == -1 || nums[i] > nums[prev])
                    take = 1 + dp[i + 1][i + 1];

                dp[i][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};

// memoisation
class Solution
{
public:
    int func(int index, int prev_index, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index >= nums.size())
            return 0;

        if (dp[index][prev_index + 1] != -1)
            return dp[index][prev_index + 1];

        int count = 0;

        count = max(count, 0 + func(index + 1, prev_index, nums, dp));

        if (prev_index == -1 || nums[index] > nums[prev_index])
            count = max(count, 1 + func(index + 1, index, nums, dp));

        return dp[index][prev_index + 1] = count;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int index = 0, prev = -1;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return func(index, prev, nums, dp);
    }
};