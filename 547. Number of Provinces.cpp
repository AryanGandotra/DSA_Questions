class Solution
{
public:
    void dfsHelper(vector<int> &visited, vector<vector<int>> &adj, int node)
    {
        visited[node] = 1;
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (adj[node][j] == 1 && visited[j] == 0)
            {
                dfsHelper(visited, adj, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
                provinces++;
            dfsHelper(visited, isConnected, i);
        }
        return provinces;
    }
};