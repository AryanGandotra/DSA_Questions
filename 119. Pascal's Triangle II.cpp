class Solution
{
public:
    int funcNCR(int n, int r)
    {
        long long res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; i++)
        {
            ans[i] = funcNCR(rowIndex, i);
        }
        return ans;
    }
};