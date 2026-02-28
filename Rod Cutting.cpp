// User function Template for C++

class Solution
{
public:
    int func(int index, vector<int> &price, int length, vector<vector<int>> &dp)
    {
        // base case
        if (index == 1)
            return length * price[0];

        if (dp[index][length] != -1)
            return dp[index][length];

        // not cut
        int notcut = func(index - 1, price, length, dp);

        int cut = INT_MIN;
        int rodLength = index;
        if (rodLength <= length)
        {
            cut = price[index - 1] + func(index, price, length - rodLength, dp);
        }

        return dp[index][length] = max(cut, notcut);
    }
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        int length = n;
        vector<vector<int>> dp(n + 1, vector<int>(length + 1, -1));
        return func(n, price, length, dp);
    }
};