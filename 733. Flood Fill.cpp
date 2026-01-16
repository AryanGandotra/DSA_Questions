class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int originalColor = image[sr][sc];
        if (originalColor == color)
            return image;

        queue<pair<int, int>> q;

        q.push({sr, sc});

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (visited[r][c] == 0)
            {
                visited[r][c] = 1;
                image[r][c] = color;

                // up
                if (r - 1 >= 0 && image[r - 1][c] == originalColor &&
                    visited[r - 1][c] == 0)
                {
                    q.push({r - 1, c});
                }

                // down
                if (r + 1 < n && image[r + 1][c] == originalColor &&
                    visited[r + 1][c] == 0)
                {
                    q.push({r + 1, c});
                }

                // left
                if (c - 1 >= 0 && image[r][c - 1] == originalColor &&
                    visited[r][c - 1] == 0)
                {
                    q.push({r, c - 1});
                }

                // right
                if (c + 1 < m && image[r][c + 1] == originalColor &&
                    visited[r][c + 1] == 0)
                {
                    q.push({r, c + 1});
                }
            }
        }
        return image;
    }
};