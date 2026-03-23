class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i <= j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(matrix[n - j - 1][i], matrix[j][i]);
            }
        }
    }
};
