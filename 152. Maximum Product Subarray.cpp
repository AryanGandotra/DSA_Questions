class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = INT_MIN, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int product = 1;
            for (int j = i; j < n; j++)
            {
                product *= nums[j];
                ans = max(ans, product);
            }
        }

        return ans;
    }
}; 