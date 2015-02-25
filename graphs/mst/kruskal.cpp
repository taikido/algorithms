/*============================================================================
* Name : kruskal.cpp
* Author: taikido
* Description: Kruskal's Algorithm for Minimum Spanning Tree Problem
* Source: http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
* Date: Sun.Feb.22.2015
This version uses the simple Union Find Algorithm - Not path compression
*===========================================================================*/

#include <climits>
#include <vector>

#include "graph.h"
#include "utility.h"


struct Comparator
{
    bool operator() (Edge* a, Edge* b)
    {
        return a->w < b->w;
    }
};

int find(vector<int> parent, int x)
{
    if (parent[x] == -1)
        return x;
    return find(parent, parent[x]);
}

void runUnion(vector<int>& parent, int x, int y)
{
    int x_set = find(parent, x);
    int y_set = find(parent, y);
    parent[x_set] = y_set;
}

void printEdges(vector<Edge*> edges)
{
    printf("Printing [%d] Edges and Weights...\n", (int)edges.size());
    for(int i=0; i<edges.size(); i++)
    {
        printf(" %d - %d [%d] \n", edges[i]->a, edges[i]->b, edges[i]->w);
    }

    cout << endl << endl;
}
vector<Edge*> kruskalMST(Graph* g)
{
    vector<Edge*> result;
    int E = g->num_edges;
    int V = g->max_v;

    vector<int> parent(V, -1);

    vector<Edge*> edges = g->edges;
    Comparator edge_weight_compare;
    sort(edges.begin(), edges.end(), edge_weight_compare);

    printEdges(edges);

    int i=0;
    while (i < E)
    {
        Edge* e = edges[i];
        int x = find(parent, e->a);
        int y = find(parent, e->b);

        if (x != y)
        {
            result.push_back(e);
            runUnion(parent, x, y);
        }

        i++;
    }

    printf("\n\n Kruskal's MST... \n\n");
    printEdges(result);
    return result;
}

void test()
{
    /* Test Graph 1: Used in Illustration Images on Geeks Tutorial page
    int a[] = {0, 0, 1, 1,  2, 2, 3, 3,  4,  5, 6, 6, 7};
    int b[] = {1, 7, 2, 7,  3, 8, 4, 5,  5,  6, 7, 8, 8};
    int w[] = {4, 8, 8, 11, 7, 2, 9, 14, 10, 2, 1, 6, 7};
    */

    /* Test Graph 2: Used in Example Code Run on Geeks Tutorial page */
    int a[] = {0,  0, 0, 1,  2};
    int b[] = {1,  2, 3, 3,  3};
    int w[] = {10, 6, 5, 15, 4};

    int n = sizeof(a)/sizeof(a[0]);

    int V = 4;

    Graph* g = new Graph(V, false);

    for(int i=0; i<n; i++)
    {
        Edge *e = new Edge(a[i], b[i], w[i]);
        g->addEdge(e);
    }

    g->print();

    printf("\n Testing Kruskal MST.... \n");
    kruskalMST(g);
}

int main()
{
    test();
}