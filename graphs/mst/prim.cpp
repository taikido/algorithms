/*============================================================================
* Name : prim.cpp
* Author: taikido
* Description: Prim's Algorithm for Minimum Spanning Tree Problem
* Source: http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
* Date: Sun.Feb.22.2015
*===========================================================================*/
#include <deque>
#include <climits>
#include <set>

#include "graph.h"
#include "utility.h"

int getMin(vector<int> key, vector<bool> mst_set)
{
    int min_val = INT_MAX;
    int min_idx = -1;

    for(int i = 0; i<key.size(); i++)
    {
        if (!mst_set[i] && key[i] < min_val)
        {
            min_val = key[i];
            min_idx = i;
        }
    }

    return min_idx;
}

Graph* getMST(Graph* g, vector<int> parent)
{

    int V = g->max_v;

    Graph* mst = new Graph(V, true);

    printf("\n\n\t *** Edges in MST *** \n\n");
    for(int i=1; i<V; i++)
    {
        printf("%d - %d    %d \n", parent[i], i, g->len(i, parent[i]));
        Edge* e = new Edge(i, parent[i], g->len(i, parent[i]));
        mst->addEdge(e);
    }

    cout << endl;
    mst->print();
}

Graph* primMST(Graph* g)
{
    int V = g->max_v;
    vector<bool> mst_set(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    key[0] = 0;

    for(int count = 0; count < V; count++)
    {
        int u = getMin(key, mst_set);
        mst_set[u] = true;

        printf("Min: %d, Key: %d \n", u, key[u]);

        vector<int> n = g->getNeighbors(u);
        for(int i=0; i<n.size(); i++)
        {
            int temp_key = g->len(u, n[i]);
            if (temp_key < key[n[i]])
            {
                key[n[i]] = temp_key;
                parent[n[i]] = u;
            }
        }
    }

    Graph* mst = getMST(g, parent);
    return mst;

}

void test()
{
    /* Test Graph 1: Used in Illustration Images on Geeks Tutorial page
    int a[] = {0, 0, 1, 1,  2, 2, 3, 3,  4,  5, 6, 6, 7};
    int b[] = {1, 7, 2, 7,  3, 8, 4, 5,  5,  6, 7, 8, 8};
    int w[] = {4, 8, 8, 11, 7, 2, 9, 14, 10, 2, 1, 6, 7};
    */

    /* Test Graph 2: Used in Example Code Run on Geeks Tutorial page */
    int a[] = {0, 0, 1, 1, 1, 2, 3};
    int b[] = {1, 3, 2, 3, 4, 4, 4};
    int w[] = {2, 6, 3, 8, 5, 7, 9};

    int n = sizeof(a)/sizeof(a[0]);

    int V = 5; // 9

    Graph* g = new Graph(V, false);

    for(int i=0; i<n; i++)
    {
        Edge *e = new Edge(a[i], b[i], w[i]);
        g->addEdge(e);
    }

    g->print();

    printf("\n Testing Prim MST.... \n");
    primMST(g);
}

int main()
{
    test();
}


/*

Printing graph...
0: [X]
1: 0(4) -> [X]
2: 8(2) -> [X]
3: 2(7) -> [X]
4: 3(9) -> [X]
5: 6(2) -> [X]
6: 7(1) -> [X]
7: 6(1) -> [X]
8: 2(2) -> [X]

*/