class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            ans[r][c] = step;

            if (r - 1 >= 0 && grid[r - 1][c] == 0 && visited[r - 1][c] == 0)
            {
                visited[r - 1][c] = 1;
                q.push({{r - 1, c}, step + 1});
            }

            if (r + 1 < n && grid[r + 1][c] == 0 && visited[r + 1][c] == 0)
            {
                visited[r + 1][c] = 1;
                q.push({{r + 1, c}, step + 1});
            }

            if (c - 1 >= 0 && grid[r][c - 1] == 0 && visited[r][c - 1] == 0)
            {
                visited[r][c - 1] = 1;
                q.push({{r, c - 1}, step + 1});
            }
            if (c + 1 < m && grid[r][c + 1] == 0 && visited[r][c + 1] == 0)
            {
                visited[r][c + 1] = 1;
                q.push({{r, c + 1}, step + 1});
            }
        }

        return ans;
    }
};