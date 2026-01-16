class Solution
{
public:
    void rotten(queue<pair<pair<int, int>, int>> &q, vector<vector<int>> &grid,
                vector<vector<int>> &visited, int n, int m, int &ansTime)
    {

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;

            q.pop();

            if (visited[r][c] == 0)
            {
                visited[r][c] = 1;
                ansTime = max(ansTime, time);

                // up
                if (r - 1 >= 0 && grid[r - 1][c] == 1 &&
                    visited[r - 1][c] == 0)
                {
                    grid[r - 1][c] = 2;
                    q.push({{r - 1, c}, time + 1});
                }

                // down
                if (r + 1 < n && grid[r + 1][c] == 1 &&
                    visited[r + 1][c] == 0)
                {
                    grid[r + 1][c] = 2;
                    q.push({{r + 1, c}, time + 1});
                }

                // left
                if (c - 1 >= 0 && grid[r][c - 1] == 1 &&
                    visited[r][c - 1] == 0)
                {
                    grid[r][c - 1] = 2;
                    q.push({{r, c - 1}, time + 1});
                }

                // right
                if (c + 1 < m && grid[r][c + 1] == 1 &&
                    visited[r][c + 1] == 0)
                {
                    grid[r][c + 1] = 2;
                    q.push({{r, c + 1}, time + 1});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        int time = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        // row,col,time

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
            }
        }

        rotten(q, grid, visited, n, m, time);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return time;
    }
};