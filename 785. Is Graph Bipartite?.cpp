class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colored(n, -1);
        queue<int> q;

        for (int start = 0; start < n; start++)
        {
            if (colored[start] != -1)
                continue;

            colored[start] = 0;
            q.push(start);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int i = 0; i < graph[node].size(); i++)
                {
                    int neighbor = graph[node][i];

                    if (colored[neighbor] == colored[node])
                        return false;

                    if (colored[neighbor] == -1)
                    {
                        colored[neighbor] = !colored[node];
                        q.push(neighbor);
                    }
                }
            }
        }

        return true;
    }
};