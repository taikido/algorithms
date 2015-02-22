/*============================================================================
* Name : graphs_weighted.cpp
* Author: taikido
* Description: Data Structure for Weighted Graph
* Date: Sat.Feb.21.2015
*===========================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;


struct Edge
{
    int a, b;
    int w;

    Edge(int a, int b, int w=0) :
        a(a), b(b), w(w)
    {}
};

struct Node
{
    Edge* data;
    Node* next;

    Node(Edge* d, Node* n) :
        data(d), next(n)
    {}
};

struct Graph
{
    bool directed;
    int max_v;
    int num_edges;
    vector<Node*> nodes;

    Graph(int v, bool directed=false) :
        directed(directed), max_v(v), num_edges(0), nodes(v)
    {}

    void addEdge(Edge* e)
    {
        nodes[e->a] = new Node(e, nodes[e->a]);
        if (!directed)
        {
            // Important for Undirected Graphs
            Edge* reverse_edge = new Edge(e->b, e->a, e->w);
            nodes[e->b] = new Node(reverse_edge, nodes[e->b]);
        }
        num_edges++;
    }

    vector<int> getNeighbors(int start)
    {
        // printf("\n*Getting neighbors of [%d] \n", start);
        Node* curr = nodes[start];
        vector<int> n;

        while(curr)
        {
            n.push_back(curr->data->b);
            curr = curr->next;
        }
        return n;
    }

    // Returns edge weight: for dijstra
    int len(int a, int b)
    {
        Node* curr = nodes[a];

        while(curr)
        {
            if (curr->data->b == b)
            {
                return curr->data->w;
            }
            curr = curr->next;
        }

        cerr << "Length not found!! " << endl;
        return 10;
    }

    void print()
    {

        printf("Printing graph... \n");
        for(int i=0; i<max_v; i++)
        {
            Node* curr = nodes[i];
            printf("%d: ", i);
            while(curr)
            {
                printf("%d(%d) -> ", curr->data->b, curr->data->w);
                curr = curr->next;
            }
            printf("[X]\n");
        }

        printf("\n");
    }
};