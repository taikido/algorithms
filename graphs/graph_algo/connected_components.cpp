#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

#include "utility.h"

using namespace std;


struct Node
{
    int data;
    Node* next;

    Node(int v, Node* n) : data(v), next(n)
    {}
};

struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
};

struct Graph
{
    int max_v;
    int num_edges;
    bool directed;
    vector<Node*> G;

    Graph(int v, bool directed = false) :
        max_v(v), num_edges(0), directed(directed), G(max_v)
    {}

    void insert(Edge& e)
    {
        G[e.v] = new Node(e.w, G[e.v]);
        if (!directed) G[e.w] = new Node(e.v, G[e.w]);
        num_edges++;
    }

    void print()
    {
        for(int i=0; i<max_v; i++)
        {
            Node* curr = G[i];
            printf("%d: ", i);
            while(curr)
            {
                printf("%d->", curr->data);
                curr = curr->next;
            }
            printf("[X]\n");
        }
        cout << endl;
    }

    vector<int> getNeighbors(int v)
    {
        vector<int> neighbors;

        Node* curr = G[v];

        while(curr)
        {
            neighbors.push_back(curr->data);
            curr = curr->next;
        }

        return neighbors;
    }
};


// dfs - stack
void dfs(Graph& g, int start, int max_v, vector<bool>& visited)
{
    deque<int> s;
    s.push_front(start);


    while(!s.empty())
    {
        int n = s.front();
        s.pop_front();

        if (!visited[n])
        {
            visited[n] = true;
            printf("%d \t", n);
            vector<int> neighbors = g.getNeighbors(n);
            for(int i=0; i<neighbors.size(); i++)
                s.push_front(neighbors[i]);
        }
    }
}

int connectedComponents(Graph& g, int max_v)
{
    vector<bool> visited(max_v, false);
    int num_cc = 0;

    for(int i=0; i<max_v; i++)
    {
        if (!visited[i])
        {
            num_cc++;
            printf("New Connected component # [%d]... \n", num_cc);
            dfs(g, i, max_v, visited); cout << endl;

            // printf("Visited.. \n");
            // printVector(visited); cout << endl;

        }
    }

    return num_cc;


}

int test()
{
    int a[] = {0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7,
                9, 10, 10, 11, 11, 12, 12, 13, 13, 0};
    int b[] = {3, 5, 7, 4, 5, 10, 0, 9, 2, 5, 6, 1, 2, 4, 4, 7, 10, 1, 6,
                3, 2, 6, 12, 13, 11, 13, 11, 12, 8};
    int n = sizeof(a)/sizeof(a[0]);

    int max_v = 14;

    Graph g(max_v);

    for(int i=0; i<n; i++)
    {
        if (b[i] > a[i])
        {
            Edge e(a[i], b[i]);
            g.insert(e);
        }

    }

    g.print();

    // printf("DFS...\n");
    // dfs(g, 1, max_v);   cout << endl;

    int cc = connectedComponents(g, max_v);

    printf("\n Number of connected components in graph: %d \n", cc);



}


int main()
{
    test();
    return 1;
}