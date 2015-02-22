// Print path between 2 nodes

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <sstream>
#include <deque>

using namespace std;


struct Node
{
    int val;
    Node* next;

    Node(int val, Node* next = 0) : val(val), next (next)
    {}

};

struct Edge
{
    int v, w;

    Edge(int v = -1, int w = -1) : v(v), w(w)
    {}
};


struct SparseGraph
{
    bool directed;
    int max_v;
    int num_edges;
    vector<Node*> G;

    SparseGraph(int max_v, int directed = false) :
        directed(directed), max_v(max_v), num_edges(0), G(max_v)
    {
        for(int i=0; i<max_v; i++)
            G[i] = 0;
    }

    int V() const { return max_v; }
    int E() const { return num_edges; }
    bool isDirected() const { return directed; }

    // Insert Edge into Graph
    void insert(const Edge& e)
    {
        G[e.v] = new Node(e.w, G[e.v]);
        if (!directed) G[e.w] = new Node(e.v, G[e.w]);
        num_edges++;
    }

    vector<int> getNeighbors(int v)
    {
        vector<int> neighbors;
        Node* curr = G[v];

        while(curr)
        {
            neighbors.push_back(curr->val);
            curr = curr->next;
        }

        return neighbors;
    }

    // Remove 1st occurrence of w at v
    void remove(const Edge& e)
    {
        int v = e.v, w = e.w;

        Node* curr = G[v];

        while (curr )
        {
            Node *next = curr->next;

            if (curr->val == w)
            {
                delete curr;
                curr = next;
                break;
            }

            curr = next;
        }
    }

    // Returns true if there is an edge: v-w
    bool edge(int v, int w) const
    {
        Node* curr = G[v];

        while (curr)
        {
            if (curr->val == w) return true;
            curr = curr->next;
        }
        return false;
    }

    void print()
    {
        for(int i=0; i<max_v; i++)
        {
            printf("%d: ", i);
            Node* curr = G[i];
            while(curr)
            {
                printf("%d->", curr->val);
                curr = curr->next;
            }
            printf("[X] \n");
        }
    }

};

typedef SparseGraph Graph;

void printVector(vector<int> v, string name)
{
    cout << "Printing Vector: " << name << endl;
    for(int i=0; i<v.size(); i++)
        printf("[%d] \t", v[i]);
    cout << endl;
}

string int2str(int i)
{
    stringstream ss;
    ss << i;
    string s = ss.str();

    return s;
}

int count = 0;
//  string s = "Neighbors of " + int2str(v);
//  printVector(neighbors, s);
void dfs(Graph& G, int v, vector<bool>& visited)
{
    count++;
    visited[v] = true;
    printf("%d \t", v);

    // Get neighbors of v and Run dfs on them
    vector<int> neighbors = G.getNeighbors(v);


    for(int i=0; i<neighbors.size(); i++)
    {
        int w = neighbors[i];
        if (!visited[w])
            dfs(G, w, visited);
    }

}

void hasCycle(Graph& G, int v, int parent, bool& has_cycle, vector<bool>& visited)
{

    visited[v] = true;
    printf("%d \t", v);

    // Get neighbors of v and Run dfs on them
    vector<int> neighbors = G.getNeighbors(v);


    for(int i=0; i<neighbors.size(); i++)
    {
        int w = neighbors[i];
        if (!visited[w])
        {
            //visited[w] = true;
            hasCycle(G, w, parent, has_cycle, visited);
        }

        // check for cycle (but disregard reverse of edge leading to v)
        // If an adjacent is visited and not parent of current vertex,
                // then there is a cycle.
        else if (w != parent)
        {
            printf("\nv: %d, u: %d \n", v, parent);
            has_cycle = true;
            return;
        }
    }

}

void printStack(deque<int> s)
{
    deque<int>::iterator it;

    for(it = s.begin(); it!= s.end(); it++)
    {
        cout << *it << "\t";
    }


}


void printPath(Graph& G, int v, int dst, vector<bool>& visited, deque<int>& s)
{
    visited[v] = true;
    s.push_front(v);

    if (v == dst)
    {
        printStack(s);
    }
    vector<int> neighbors = G.getNeighbors(v);

    for(int i=0; i<neighbors.size(); i++)
    {
        int w = neighbors[i];
        if (!visited[w])
        {
            printPath(G, w, dst, visited, s);
        }
    }
    s.pop_front();
}


void test()
{
    int a[] = {0, 0, 0, 0, 3, 4, 4, 7, 9,  9,  9};
    int b[] = {1, 2, 5, 6, 5, 5, 6, 8, 10, 11, 12};

    // Important: Set max_V to number of nodes but insert n items into G
    int n = sizeof(a)/sizeof(a[0]);
    int num_nodes = 13;
    int max_v = num_nodes;

    printf("num_nodes: %d \n", num_nodes);

    SparseGraph G(max_v);

    for(int i=0; i<n; i++)
    {
        printf("[%d] --> (%d, %d) \n", i, a[i], b[i]);
        Edge e(a[i], b[i]);
        G.insert(e);
    }

    cout << endl << endl;
    G.print();

    vector<bool> visited(max_v, false);
    bool has_cycle = false;
    hasCycle(G, 0, 0, has_cycle, visited);

    cout << endl << endl;
//  dfs(G, 0, visited);  // iterative: 0    1   2   5   3   4   6 recursive: 0  6   4   5   3   2   1

    cout << "\nIs 7 connected to 0? " << visited[7] << endl;
    cout << "Is there a path from 0 t0 4? " << visited[4] << endl;
    cout << "Number of vertices connected to 0: " << count << endl;


    cout << "Does Graph starting at 0 have cycle? " << has_cycle << endl;

    cout << endl << endl;

    visited.assign(max_v, false);
    has_cycle = false;
    hasCycle(G, 7, 7, has_cycle, visited);
    cout << "\nDoes Graph starting at 7 have cycle? " << has_cycle << endl;

    // Print Path
    visited.assign(max_v, false);
    deque<int> s;
    printPath(G, 2, 4, visited, s);

    //count = 0;
//  visited.assign(max_v, false);
//  dfs(G, 7, visited); // 7    8
//  //cout << "count: " << count << endl;
//
//  cout << endl << endl;
//
//  //count = 0;
//  visited.assign(max_v, false);
//  dfs(G, 9, visited); // 9    10  11  12 recursive: 9     12  11  10
//  //cout << "count: " << count << endl;
//  cout << endl << endl;
}


int main() {
    cout << "Wa de gwaan werl!" << endl; // prints Wa de gwaan werl!

    test();

    return 0;
}
