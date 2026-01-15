class Solution
{
public:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // up
            if (r - 1 >= 0 && grid[r - 1][c] == '1' && visited[r - 1][c] == 0)
            {
                visited[r - 1][c] = 1;
                q.push({r - 1, c});
            }

            // down
            if (r + 1 < n && grid[r + 1][c] == '1' && visited[r + 1][c] == 0)
            {
                visited[r + 1][c] = 1;
                q.push({r + 1, c});
            }

            // left
            if (c - 1 >= 0 && grid[r][c - 1] == '1' && visited[r][c - 1] == 0)
            {
                visited[r][c - 1] = 1;
                q.push({r, c - 1});
            }

            // right
            if (c + 1 < m && grid[r][c + 1] == '1' && visited[r][c + 1] == 0)
            {
                visited[r][c + 1] = 1;
                q.push({r, c + 1});
            }

            // // top-left
            // if (r - 1 >= 0 && c - 1 >= 0 &&
            //     grid[r-1][c-1] == '1' && visited[r-1][c-1] == 0) {
            //     visited[r-1][c-1] = 1;
            //     q.push({r-1, c-1});
            // }

            // // bottom-right
            // if (r + 1 < n && c + 1 < m &&
            //     grid[r+1][c+1] == '1' && visited[r+1][c+1] == 0) {
            //     visited[r+1][c+1] = 1;
            //     q.push({r+1, c+1});
            // }

            // // bottom-left
            // if (r + 1 < n && c - 1 >= 0 &&
            //     grid[r+1][c-1] == '1' && visited[r+1][c-1] == 0) {
            //     visited[r+1][c-1] = 1;
            //     q.push({r+1, c-1});
            // }

            // // top-right
            // if (r - 1 >= 0 && c + 1 < m &&
            //     grid[r-1][c+1] == '1' && visited[r-1][c+1] == 0) {
            //     visited[r-1][c+1] = 1;
            //     q.push({r-1, c+1});
            // }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int islands = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] == '1' && visited[row][col] == 0)
                {
                    bfs(row, col, visited, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};