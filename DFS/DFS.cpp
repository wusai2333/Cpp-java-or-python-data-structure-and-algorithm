// C++ program to print DFS traversal from a given vertex in a given graph
#include <iostream>
#include <list>
using namespace std;

// Graph class represents a direct a direct graph using adjacency list representation
class Graph
{
    int V; // no. of vertices
    list<int> *adj; // Pointer to an array containing adjacency list
    void DFSUtil (int v, bool visited[]); // A function used by DFS
public:
    Graph(int V); // constructor
    void addEdge(int v, int w); // function to add and edge to graph
    void DFS(); // DFS traversal of the vertices reachable from v
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's adj list
}
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjcent to this vertex
    for (auto i : adj[v])
    {
        if (!visited[i])
            DFSUtil(i, visited);
    }
}

// DFS trversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS()
{
    //Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}

int main()
{
    //Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth first Traversal (start from vertex 2) \n";
    g.DFS();

    return 0;

}
