/*============================================================================
* Name : strongly_connected_components.cpp
* Author: taikido
* Description: Strongly Connected Components in a Graph
* Source: http://www.geeksforgeeks.org/strongly-connected-components/
* Date: Tues.Feb.24.2015
*===========================================================================*/

#include <vector>
#include <deque>

#include "graph.h"
#include "utility.h"

using namespace std;

void topSort(Graph*g, int v, vector<bool>& visited, deque<int>& stack)
{
    visited[v] = true;

    vector<int> n = g->getNeighbors(v);
    for(int i=0; i<n.size(); i++)
    {
        if (!visited[n[i]])
            topSort(g, n[i], visited, stack);
    }

    stack.push_front(v);
}

void dfs(Graph*g, int v, vector<bool>& visited)
{
    visited[v] = true;
    printf("%d \t", v);

    vector<int> n = g->getNeighbors(v);
    for(int i=0; i<n.size(); i++)
    {
        if (!visited[n[i]])
            dfs(g, n[i], visited);
    }
}


void getSCCs(Graph* g)
{
    int V = g->V();
    vector<bool> visited(V, false);
    deque<int> stack;

    // Get order to traverse graph for Strongly Connected Components
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            topSort(g, i, visited, stack);
    }

    // Get SCCs
    visited.assign(V, false);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            int u = stack.front();
            stack.pop_front();

            dfs(g, u, visited);
        }
    }
}

int main()
{
    return 0;
}


