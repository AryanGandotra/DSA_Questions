class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &visited,
             vector<vector<char>> &board, int n, int m)
    {
        visited[i][j] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++)
        {
            int ni = i + delRow[k];
            int nj = j + delCol[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                visited[ni][nj] == 0 && board[ni][nj] == 'O')
            {
                dfs(ni, nj, visited, board, n, m);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // traverse first and last row
        for (int j = 0; j < m; j++)
        {
            if (visited[0][j] == 0 && board[0][j] == 'O')
            {
                dfs(0, j, visited, board, n, m);
            }
            if (visited[n - 1][j] == 0 && board[n - 1][j] == 'O')
            {
                dfs(n - 1, j, visited, board, n, m);
            }
        }

        // traverse first and last col
        for (int i = 0; i < n; i++)
        {
            if (visited[i][0] == 0 && board[i][0] == 'O')
            {
                dfs(i, 0, visited, board, n, m);
            }
            if (visited[i][m - 1] == 0 && board[i][m - 1] == 'O')
            {
                dfs(i, m - 1, visited, board, n, m);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};