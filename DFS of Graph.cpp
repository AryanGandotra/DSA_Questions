class Solution
{
public:
    void dfsHelper(vector<int> &ans, vector<int> &visited, vector<vector<int>> &adj, int node)
    {
        visited[node] = 1;
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbor = adj[node][j];
            if (visited[neighbor] == 0)
            {
                dfsHelper(ans, visited, adj, adj[node][j]);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj)
    {
        vector<int> ans;
        vector<int> visited(adj.size(), 0);
        visited[0] = 1;
        dfsHelper(ans, visited, adj, 0);
        return ans;
    }
};