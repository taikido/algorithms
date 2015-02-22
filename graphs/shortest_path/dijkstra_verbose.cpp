/*============================================================================
* Name : dijkstra.cpp
* Author: taikido
* Description: Dijstra in an Undirected Weighted Graph
* Date: Sat.Feb.21.2015
*===========================================================================*/
#include <deque>
#include <climits>
#include <set>

#include "graph.h"
#include "utility.h"


int getMin(set<int> s)
{
    set<int>::iterator it;
    int min_val = INT_MAX;

    for(it = s.begin(); it != s.end(); it++)
    {
        if (*it < min_val)
            min_val = *it;
    }

    printf("min_val: %d \n", min_val);

    return min_val;
}

int getMinIdx(vector<int> dist)
{


    cout << "Dist... \n";    printVector(dist); cout << endl;
    int min_val = INT_MAX;
    int min_idx = 0;
    for(int i=0; i<dist.size(); i++)
    {
        if (dist[i] < min_val)
        {
            min_val = dist[i];
            min_idx = i;
        }
    }

    printf("min_idx: %d, min_val: %d \n", min_idx, min_val);

    return min_idx;
}



// return vertex in q with min dist
int getMinIdx(set<int> q, vector<int> dist, int& min_val)
{
    // int min_val = INT_MAX;
    int min_idx = 0;

    for(int i=0; i<dist.size(); i++)
    {
        // Only find min dist of elements in unvisited set
        if (q.find(i) != q.end() && dist[i] < min_val)
        {
            min_val = dist[i];
            min_idx = i;
        }
    }

    printf("min_idx: %d, min_val: %d \n", min_idx, min_val);

    return min_idx;
}

/*
    Notes on input:
        Initialize dist with INT_MAX for all nodes except s
        dist[s] = 0;
*/

int jj = 0;
bool dijkstra(Graph* g, int src, int dst, vector<int>& dist, vector<int>& prev)
{
    vector<bool> visited(g->max_v, false);
    set<int> q; // vector<int> q;

    for(int i=0; i<g->max_v; i++)
    {
        q.insert(i); //q.push_back(i);
    }

    while(!q.empty())
    {
        jj++;
        int min_val = INT_MAX;
        int v = getMinIdx(q, dist, min_val);
        q.erase(v);

        if (v == dst)
        {
            printf("Arrived at Node: [%d]. Aborting...\n\n", v);
            return true;
        }
        if (min_val == INT_MAX)
        {
            printf("Cant get to Node [%d] from [%d]", dst, src);
            return false;
        }

        printf("\n *Visit [%d] \n\n", v);

        visited[v] = true;
        printf("q...\n"); printSet(q); cout << endl;

        vector<int> n = g->getNeighbors(v);
        printf("neighbors...\n"); printVector(n); cout << endl;
        for(int i=0; i<n.size(); i++)
        {
            if(!visited[n[i]])
            {
                int temp_dist = dist[v] + g->len(v, n[i]);
                printf("temp_dist: %d, dist[n[i]]: %d, s: %d, i: %d\n",
                        temp_dist, dist[n[i]], v, i);
                if (temp_dist < dist[n[i]])
                {
                    dist[n[i]] = temp_dist;
                    prev[n[i]] = v;
                }
            }
        }

        if (jj > 10) return false;
    }

}

// n - number of nodes in graph
void getPath(int src, int dst, vector<int> prev, int n, vector<int>& path)
{

    int curr = dst;
    int i = 0;
    path.push_back(dst);
    while(i <= n)
    {
        path.push_back(prev[curr]);
        if (prev[curr] == src) break;
        curr = prev[curr];
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

    printf("Dijkstra \n");
    vector<bool> visited(max_v, false);


    int src = 0;
    int dst = 4;
    vector<int> dist(max_v, INT_MAX);
    dist[src] = 0;
    vector<int> prev(max_v, -1);
    dijkstra(g, src, dst,  dist, prev);

    printf("Printing previous vector... \n");
    printVector(prev); cout << endl;

    vector<int> path;
    int num_graph_nodes = max_v;

    getPath(src, dst, prev, num_graph_nodes, path);

    reverse(path.begin(), path.end());

    printf("Printing Shortest Path from [%d] to [%d]... \n", src, dst);
    printVector(path); cout << endl;

}

int main()
{
    test();
}



        //s = minIdx(q, dist); // returns index of min dist
        //q.erase(q.begin()+s); // Remove s from q


// return vertex in q with min dist
int getMinIdx2(vector<int> q, vector<int> dist)
{


    // vector<int> v; //distances of elements in q (unvisited_dist)

    // set<int>::iterator it;
    // for(it = q.begin(); it != q.end(); it++)
    // {
    //     v.push_back(dist[*it]);
    // }

    vector<int> v; //distances of elements in q

    for(int i=0; i<q.size(); i++)
    {
        v.push_back(dist[q[i]]);
    }
    int min_val = INT_MAX;
    int min_idx = 0;
    for(int i=0; i<v.size(); i++)
    {
        if (v[i] < min_val)
        {
            min_val = v[i];
            min_idx = q[i];
        }
    }

    printf("min_idx: %d, min_val: %d \n", min_idx, min_val);

    return min_idx;
}