// recursive - will fail in LC submission

class Solution
{
public:
    int getMinPathSum(int m, int n, vector<vector<int>> &grid)
    {
        if (m == 0 && n == 0)
            return grid[0][0];

        int up = INT_MAX, left = INT_MAX;

        if (m - 1 >= 0)
            up = grid[m][n] + getMinPathSum(m - 1, n, grid);
        if (n - 1 >= 0)
            left = grid[m][n] + getMinPathSum(m, n - 1, grid);

        return min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        return getMinPathSum(m - 1, n - 1, grid);
    }
};