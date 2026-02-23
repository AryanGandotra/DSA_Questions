#include <bits/stdc++.h>

bool GetSubArrays(int index, vector<int> &nums, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;

    if (index == nums.size())
        return false;

    if (dp[index][k] != -1)
        return dp[index][k];

    bool take = false;
    if (k >= nums[index])
        take = GetSubArrays(index + 1, nums, k - nums[index], dp);

    bool notTake = GetSubArrays(index + 1, nums, k, dp);

    return dp[index][k] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return GetSubArrays(0, arr, k, dp);
}