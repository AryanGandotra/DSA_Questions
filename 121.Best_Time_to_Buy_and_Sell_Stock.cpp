class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int l = 0, r = 1;
        while (r < prices.size())
        {
            if (prices[l] < prices[r])
            {
                ans = max(ans, prices[r] - prices[l]);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return ans;
    }
};