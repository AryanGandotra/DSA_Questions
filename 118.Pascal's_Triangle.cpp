class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> ans(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                ans[j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(ans);
        }

        return result;
    }
};

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

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++)
        {
            result.push_back(getRow(i));
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
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++)
        {
            result.push_back(getRow(i));
        }

        return result;
    }
};