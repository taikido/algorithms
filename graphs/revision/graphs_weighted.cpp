/*============================================================================
* Name : graphs_weighted.cpp
* Author: taikido
* Description: Data Structure and Search for Weighted Graphs
* Date: Sat.Feb.21.2015
*===========================================================================*/
#include <deque>

#include "graph.h"
#include "utility.h"

// Recursive dfs
void dfsR(Graph* g, int start, vector<bool>& visited)
{
    visited[start] = true;
    printf("%d \t", start);

    vector<int> n = g->getNeighbors(start);
    // printVector(n);
    for(int i=0; i<n.size(); i++)
    {
        if (!visited[n[i]])
            dfsR(g, n[i], visited);
    }
}


// Iterative DFS
void dfs(Graph* g, int v, vector<bool>& visited)
{
    deque<int> stack;
    stack.push_front(v);

    while(!stack.empty())
    {
        v = stack.front();
        stack.pop_front();
        printf("%d ", v);

        vector<int> n = g->getNeighbors(v);
        for(int i=0; i<n.size(); i++)
        {
            if (!visited[n[i]])
            {
                stack.push_front(n[i]);
                visited[n[i]] = true;
            }
        }
    }
}

// Iterative BFS
void bfs(Graph* g, int v, vector<bool>& visited)
{
    deque<int> q;
    q.push_back(v);

    while(!q.empty())
    {
        v = q.front();
        q.pop_front();
        printf("%d ", v);

        vector<int> n = g->getNeighbors(v);
        for(int i=0; i<n.size(); i++)
        {
            if (!visited[n[i]])
            {
                q.push_back(n[i]);
                visited[n[i]] = true;
            }
        }
    }
}

// Number of Connected Components
int cc(Graph* g)
{
    int count = 0;

    vector<bool> visited(g->max_v, false);

    printf("Connected Components in Graph are: ...\n");
    for(int i=0; i<g->max_v; i++)
    {
        if (!visited[i])
        {
            dfs(g, i, visited); cout << endl << endl;
            count++;
        }
    }

    return count;
}

bool hasCycle(Graph* g, int v, vector<bool>& visited, vector<bool>& marked)
{
    visited[v] = true;
    marked[v] = true;
    vector<int> n = g->getNeighbors(v);

    for(int i=0; i<n.size(); i++)
    {
        if (!visited[n[i]])
        {
            hasCycle(g, n[i], visited, marked);
        }
        else if (marked[v])
            printf("**Found cycle at: %d \n", v);
    }
    marked[v] = false;
}

bool isBipartite(Graph* g, int v, bool c, vector<bool>& visited, vector<bool>& color)
{
    visited[v] = true;
    color[v] = c;
    vector<int> n = g->getNeighbors(v);

    for(int i=0; i<n.size(); i++)
    {
        if (!visited[n[i]])
        {
            isBipartite(g, n[i], !c, visited, color);
        }
        else if (color[v] == color[n[i]])
            printf("NOT Bipartite \n", v);
    }
}

void test()
{
    int a[] = {0, 0, 0,  1,   1, 2,  2, 3, 4, 6, 7};
    int b[] = {1, 2, 5,  2,   3, 3,  5, 4, 5, 7, 8};
    int w[] = {7, 9, 14, 10, 15, 11, 2, 6, 9, 2, 4};
    int n = sizeof(a)/sizeof(a[0]);

    int max_v = 9;

    Graph* g = new Graph(max_v, false);

    for(int i=0; i<n; i++)
    {
        Edge *e = new Edge(a[i], b[i], w[i]);
        g->addEdge(e);
    }

    g->print();

    printf("Recursive DFS \n");
    vector<bool> visited(max_v, false);
    dfsR(g, 0, visited);  cout << endl << endl;

    printf("Iterative DFS \n");
    visited.assign(max_v, false);
    dfs(g, 0, visited); cout << endl << endl;

    printf("Iterative BFS \n");
    visited.assign(max_v, false);
    bfs(g, 0, visited); cout << endl << endl;

    int c = cc(g);
    printf("Number of connected components in graph: %d\n\n", c);

    vector<bool> marked(max_v, false);
    visited.assign(max_v, false);
    hasCycle(g, 0, visited, marked);

    vector<bool> color(max_v, false);
    visited.assign(max_v, false);
    bool col = 0;
    isBipartite(g, 0, col, visited, color);


}

int main()
{
    test();
}