/*============================================================================
* Name : dense_graph.cpp
* Author: taikido
* Description: Dense Graph
* Source: Adapted from Sedgewick Chapter 17
* Date: Jan.2015
* Updated: Sat.Feb.7.2015
*===========================================================================*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


struct Edge
{
  int v, w;

  Edge(int v = -1, int w = -1) : v(v), w(w)
  {}
};


struct DenseGraph
{
  int max_v;
  int num_edges;
  bool directed;
  vector<vector<bool> > G;

  DenseGraph(int max_v, bool directed=false) : max_v(max_v), num_edges(0), directed(directed), G(max_v)
  {
    for (int i=0; i<max_v; i++)
      G[i].assign(max_v, false);

    //printf("\n rows: %d, cols: %d \n", G.size(), G[0].size());
  }

  int V() const { return max_v; }
  int E() const { return num_edges; }
  bool isDirected() const { return directed; }


  // Insert an Edge into the Graph
  void insert(const Edge& e)
  {
    //printf("[%d] --> Inserting {%d, %d} into graph \n", num_edges, e.v, e.w);
    int v = e.v, w = e.w;
    if (G[v][w] == false) num_edges++;
    G[v][w] = true;
    if (!directed) G[w][v] = true;

    if (num_edges == 10) print();
  }

  // Remove an Edge from a Graph
  void remove(const Edge& e)
  {
    int v = e.v, w = e.w;
    if (G[v][w] == false) num_edges--;
    G[v][w] = false;
    if (!directed) G[w][v] = false;
  }

  // Retrieve value of edge
  bool edge(int v, int w)
  {
    return G[v][w];
  }

  void print()
  {
    printf("\nGraph (Adjacency Matrix Representation... \n\n");
    for(int i=0; i<max_v; i++)
    {
      for(int j=0; j<max_v; j++)
          cout << G[i][j] << "\t";

      cout << endl;
    }
  }
};

void test()
{
  int a[] = {0, 0, 0, 0, 3, 4, 4, 7, 9,  9,  9};
  int b[] = {1, 2, 5, 6, 5, 5, 6, 8, 10, 11, 12};

  // Important: Set max_V to number of nodes but insert n items into G
  int n = sizeof(a)/sizeof(a[0]);
  int num_nodes = 13;
  int max_v = num_nodes;

  printf("num_nodes: %d \n", num_nodes);

  DenseGraph G(max_v);

  for(int i=0; i<n; i++)
  {
    //printf("[%d] --> (%d, %d) \n", i, a[i], b[i]);
    Edge e(a[i], b[i]);
    G.insert(e);
  }

  cout << "here: " << endl;
  G.print();
}



int main() {
  cout << "Wa de gwaan werl!" << endl; // prints Wa de gwaan werl!

  test();

  return 0;
}
