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