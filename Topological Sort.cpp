class Solution
{
public:
    void dfs(int node, vector<int> &visited, stack<int> &st, vector<vector<int>> &adj)
    {
        visited[node] = 1;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, visited, st, adj);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> result;
        vector<int> visited(V, 0);

        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
        }

        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
                dfs(i, visited, st, adj);
        }

        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};