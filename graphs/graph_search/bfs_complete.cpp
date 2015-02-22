#include <iostream>
#include <cstdio>
#include <vector>
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



void enqueue(deque<int>& q, int x)
{
    q.push_back(x);
}

int dequeue(deque<int>& q)
{
    int x = q.front();
    q.pop_front();
    return x;
}

typedef SparseGraph Graph;

void bfs(Graph& G, int v)
{
    deque<int> q;
    vector<bool> visited(G.V());

    enqueue(q, v);

    while(!q.empty())
    {
        v = dequeue(q);

        if (!visited[v])
        {
            visited[v] = true;
            printf("%d \t", v);

            Node* curr = G.G[v];
            while(curr)
            {
                enqueue(q, curr->val);
                curr = curr->next;
            }
        }
    }
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

    cout << endl << endl;
    bfs(G, 0); // 0     6   5   2   1   4   3
    cout << endl << endl;
    bfs(G, 7); // 7 8
    cout << endl << endl;
    bfs(G, 9); // 9     12  11  10
    cout << endl << endl;;
}

int main() {
    cout << "Wa de gwaan werl!" << endl; // prints Wa de gwaan werl!

    test();
    return 0;
}
