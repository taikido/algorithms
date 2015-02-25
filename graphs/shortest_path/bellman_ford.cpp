/*============================================================================
* Name : bellman_ford.cpp
* Author: taikido
* Description: Bellman-Ford Algorithm for Single Source Shortest Path
* Source: http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/
* Date: Wed.Feb.25.2015
*===========================================================================*/

#include "graph.h"
#include "utility.h"
#include <climits>

using namespace std;


void printDist(vector<int> dist, vector<int> parent, int src)
{
    printf("Printing Shortest Paths from [%d] \n", src);
    for(int i=0; i<dist.size(); i++)
        printf("%d \t (%d : %d) \n", i, parent[i], dist[i]);

    cout << endl << endl;
}

bool bellman_ford(Graph* g, int src)
{
    int V = g->V();
    int E = g->E();

    vector<Edge*> edges = g->edges;

    int INF = INT_MAX;
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    dist[src] = 0;

    for(int i=0; i<V-1; i++)
    {
        for(int j=0; j<E; j++)
        {
            int u = edges[j]->a;
            int v = edges[j]->b;

            int temp_dist = dist[u] == INF ? INF : dist[u] + edges[j]->w;

            printf("u: %d, v: %d, temp_dist: %d \n", u, v, temp_dist);
            if (temp_dist < dist[v])
            {
                dist[v] = temp_dist;
                parent[v] = u;
            }
        }
    }

    for(int j=0; j<E; j++)
    {
        int u = edges[j]->a;
        int v = edges[j]->b;

        int temp_dist = dist[u] == INF ? INF : dist[u] + edges[j]->w;
        if (temp_dist < dist[v])
        {
            printf("Negative Weight Cycle Found!! \n");
            return false;
        }
    }

    printDist(dist, parent, src);
    return true;
}

void test()
{
    int a[] = {0, 0, 1, 1, 1, 3, 3,  4};
    int b[] = {1, 2, 2, 3, 4, 1, 2,  3};
    int w[] = {-1, 4, 3, 2, 2, 1, 5, -3};

    int n = sizeof(a)/sizeof(a[0]);

    int V = 5;

    Graph* g = new Graph(V, true);

    for(int i=0; i<n; i++)
    {
        Edge *e = new Edge(a[i], b[i], w[i]);
        g->addEdge(e);
    }

    g->print();

    printf("\n Testing Bellman-Ford.... \n");

    int src = 0;
    bellman_ford(g, src);
}

int main()
{
    test();
}