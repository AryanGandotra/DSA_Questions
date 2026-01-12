class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        vector<int> ans;
        vector<int> visited(adj.size(), 0);

        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int i = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int j = 0; j < adj[node].size(); j++)
            {
                int neighbor = adj[node][j];

                if (visited[neighbor] == 0)
                {
                    q.push(neighbor);
                    visited[neighbor] = 1;
                }
            }
        }

        return ans;
    }
};