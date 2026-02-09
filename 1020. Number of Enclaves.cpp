class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1)
                {
                    visited[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            if (row + 1 < n && visited[row + 1][col] == 0 &&
                grid[row + 1][col] == 1)
            {
                visited[row + 1][col] = 1;
                q.push({row + 1, col});
            }

            if (row - 1 >= 0 && visited[row - 1][col] == 0 &&
                grid[row - 1][col] == 1)
            {
                visited[row - 1][col] = 1;
                q.push({row - 1, col});
            }
            if (col + 1 < m && visited[row][col + 1] == 0 &&
                grid[row][col + 1] == 1)
            {
                visited[row][col + 1] = 1;
                q.push({row, col + 1});
            }
            if (col - 1 >= 0 && visited[row][col - 1] == 0 &&
                grid[row][col - 1] == 1)
            {
                visited[row][col - 1] = 1;
                q.push({row, col - 1});
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};