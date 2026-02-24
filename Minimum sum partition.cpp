class Solution
{

public:
    int minDifference(vector<int> &nums)
    {

        int k = 0, n = nums.size();

        if (n == 1)
            return nums[0];

        for (int i = 0; i < nums.size(); i++)
            k += nums[i];
        int Ksum = k;
        k = k / 2;

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

        int ans = 1e9;

        for (int i = 0; i <= k; i++)
        {
            if (dp[i])
                ans = min(ans, abs(Ksum - (2 * i)));
        }

        return ans;
    }
};
