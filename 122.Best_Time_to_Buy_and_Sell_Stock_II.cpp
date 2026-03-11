// memoisation
class Solution {
public:
    long func(int index,int canBuy,vector<int>& prices,vector<vector<int>> &dp){
        if(index==prices.size())
            return 0;
        
        if(dp[index][canBuy]!=-1)
            return dp[index][canBuy];

        long profit=0;

        if(canBuy==1)
            profit = max((-prices[index] + func(index+1,0,prices,dp)),func(index+1,1,prices,dp));
        else 
            profit = max((prices[index] + func(index+1,1,prices,dp)),func(index+1,0,prices,dp));

        return dp[index][canBuy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int canBuy=1,index=0;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return func(index,canBuy,prices,dp);
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                ans += (prices[i] - prices[i - 1]);
        }
        return ans;
    }
};