/*============================================================================
* Name : graph_adt.cpp
* Author: taikido
* Description: Graph ADT
* Source: Sedgewick Chapter 17
* Date: Jan.2015
*===========================================================================*/

struct Edge
{
  int v, w;
  Edge(int v = -1, int w =-1) : v(v), w(w)
  {}
};


/*
1. The graph constructor takes the maximum possible number of vertices in the graph as an argument, and a boolean that tells whether the graph is undirected or directed (a digraph), with undirected the default.
*/
class Graph
{
  private:
    // Implementation-dependent code
  public:
    Graph(int V, bool directed = false);
    ~Graph();
    int V() const; // returns max possible number of vertices in graph
    int E() const; // returns number of edges in graph
    bool directed const;
    int insert(Edge);
    int remove(Edge);
    bool edge(int a, int b);

    class AdjIterator
    {
      public:
        AdjIterator(const Graph& g, int );
        int begin();
        int next();
        int end();
    };

};

