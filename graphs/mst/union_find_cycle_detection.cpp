/*============================================================================
* Name : union_find_cycle_detection.cpp
* Author: taikido
* Description: Cycle Detection using Union Find
* Source: http://www.geeksforgeeks.org/union-find/
* Date: Sun.Feb.22.2015
*===========================================================================*/
#include <deque>
#include <climits>
#include <vector>

#include "graph.h"
#include "utility.h"


int find(vector<int> parent, int x)
{
    if (parent[x] == -1)
        return x;
    return find(parent, parent[x]);
}

// Remember that union is a keyword in C++
void getUnion(vector<int>& parent, int x, int y)
{
    int x_set = find(parent, x);
    int y_set = find(parent, y);

    parent[x_set] = y_set;
}

bool isCycle(Graph* g)
{
    int E = g->num_edges;
    int V = g->max_v;

    vector<int> parent(V, -1);

    for(int i=0; i<E; i++)
    {
        // Iterate through all edges attached to a Node
        Edge* e = g->edges[i];
        int x_set = find(parent, e->a);
        int y_set = find(parent, e->b);
        printf("Edge (%d - %d) \n", e->a, e->b);

        if (x_set == y_set) return true;
        getUnion(parent, x_set, y_set);

    }

    return false;
}


void test()
{
    // Cycle
    /* */
    // int a[] = {0, 0, 1};
    // int b[] = {1, 2, 2};


    // No Cycle
    int a[] = {0, 1};
    int b[] = {1, 2};
    int n = sizeof(a)/sizeof(a[0]);

    int V = 3;

    Graph* g = new Graph(V, false);

    for(int i=0; i<n; i++)
    {
        Edge *e = new Edge(a[i], b[i]);
        g->addEdge(e);
    }

    g->print();

    printf("\n Testing Cycle Detection.... \n");
    bool cycle = isCycle(g);

    cout << "Is there a cycle in the graph? " << cycle << endl;

}

int main()
{
    test();
}