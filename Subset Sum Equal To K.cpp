// tabulation + space optimisation

#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &nums)
{
    vector<bool> dp(k + 1, false);
    dp[0] = true;

    if (nums[0] <= k)
        dp[nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(k + 1, false);
        curr[0] = true;
        for (int j = 1; j <= k; j++)
        {
            bool take = false;
            if (j >= nums[i])
                take = dp[j - nums[i]];

            bool notTake = dp[j];

            curr[j] = take || notTake;
        }
        dp = curr;
    }
    return dp[k];
}

// tabulation
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &nums){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));

    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    
    if(nums[0] <= k)
        dp[0][nums[0]] = true;


    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
                bool take = false;
                if (j >= nums[i])
                    take = dp[i-1][j - nums[i]];

                bool notTake = dp[i-1][j];

                dp[i][j] = take || notTake;
        }
    }
    return dp[n-1][k];
}

// memoisation
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