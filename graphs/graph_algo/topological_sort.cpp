/*============================================================================
* Name : topological_sort.cpp
* Author: taikido
* Description: Topological Sorting Algorithm for a DAG
* Source: http://www.geeksforgeeks.org/topological-sorting/
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

int main()
{
    return 0;
}