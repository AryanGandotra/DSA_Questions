class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result(rowIndex + 1, 1);
        long long ans = 1, row = rowIndex;

        for (int i = 1; i <= rowIndex / 2; i++)
        {
            ans = (ans * row) / i;
            result[i] = ans;
            result[rowIndex - i] = ans;
            row--;
        }

        return result;
    }
};

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