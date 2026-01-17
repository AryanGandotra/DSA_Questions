class Solution
{
public:
    bool detect(int src, vector<vector<int>> &adj, vector<int> &visited)
    {
        queue<pair<int, int>> q;
        visited[src] = 1;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = 1;
                    q.push({neighbor, node});
                }
                else if (neighbor != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        // Convert edge list to adjacency list
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detect(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
