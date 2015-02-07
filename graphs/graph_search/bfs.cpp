void bfs(const Graph& G, int V, int v, vector<bool> visited)
{
    deque<int> q;
    q.push_back(v);

    while(!q.empty())
    {
        v = q.front();
        q.pop_front();

        if (!visited[v])
        {
            visited[v] = true;
            printf("%d \t", v);
            Graph::iterator it(G, v);

            for(int w=it.begin(); !it.end(); w=it.next())
            {
                q.push_back(w);
            }
        }
    }
}
