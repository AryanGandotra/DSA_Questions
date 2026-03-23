class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> copy = matrix;

        int n = matrix.size() - 1, m = matrix.size();

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][j] = copy[n - j][i];
            }
        }
    }
};