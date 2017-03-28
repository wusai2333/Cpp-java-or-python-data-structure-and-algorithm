<<<<<<< HEAD
// C++ implementation of kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int V; // no. of vertices
    list<int> *adj; // An array of adjency lists;
    // Fill Stack with vertices (in increasing order of finishing times). The top element of stack has maximum finishing times
    void fillOrder(int v, bool visited[], stack<int> &Stack);
    // A recursive function to print DFS starting from
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);

    // The main function that finds and print the strongly connected components
    void printSCCs();
    // Function that returns reverse(or transpose) of this graph.
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
// A recursive funtion to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
    //Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    //Recur for all the vertices adjcent to this vertex
    for (auto i : adj[v])
        if(!visited[i])
            DFSUtil(i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        for(auto i : adj[v])
        {
            g.adj[i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v 's list;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    // Recur for all the vertices adjcent to this vertex
    for (auto i : adj[v])
        if(!visited[i])
            fillOrder(i, visited, Stack);

    // All vertices reachable from v are processed by now , push v
    Stack.push(v);
}
// The main function that finds and prints all strongly connected components
void Graph::printSCCs()
{
    stack<int> Stack;
    // Mark all the vertices as not visited (For visited DFS)
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a reversed Graph
    Graph gr = getTranspose();
    // Fill vertices in stack according to their finishing times
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            gr.fillOrder(i, visited, Stack);

    // Mark all the vertices as not visited (For second DFS)
    for (int i = 0; i < V; i++)
        visited[i] = false;

    //Now process all vertices in order defined by Stack;
    while (!Stack.empty())
    {
        // Pop a vertex from the Stack
        int v = Stack.top();
        Stack.pop();

        //Print Strongly connected components of the popped vertex
        if (visited[v] == false)
        {
            DFSUtil(v, visited);
            cout << endl;
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in given Graph \n";
    g.printSCCs();
    return 0;
}
=======
// C++ implementation of kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int V; // no. of vertices
    list<int> *adj; // An array of adjency lists;
    // Fill Stack with vertices (in increasing order of finishing times). The top element of stack has maximum finishing times
    void fillOrder(int v, bool visited[], stack<int> &Stack);
    // A recursive function to print DFS starting from
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);

    // The main function that finds and print the strongly connected components
    void printSCCs();
    // Function that returns reverse(or transpose) of this graph.
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
// A recursive funtion to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
    //Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    //Recur for all the vertices adjcent to this vertex
    for (auto i : adj[v])
        if(!visited[i])
            DFSUtil(i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        for(auto i : adj[v])
        {
            g.adj[i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v 's list;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    // Recur for all the vertices adjcent to this vertex
    for (auto i : adj[v])
        if(!visited[i])
            fillOrder(i, visited, Stack);

    // All vertices reachable from v are processed by now , push v
    Stack.push(v);
}
// The main function that finds and prints all strongly connected components
void Graph::printSCCs()
{
    stack<int> Stack;
    // Mark all the vertices as not visited (For visited DFS)
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a reversed Graph
    Graph gr = getTranspose();
    // Fill vertices in stack according to their finishing times
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            gr.fillOrder(i, visited, Stack);

    // Mark all the vertices as not visited (For second DFS)
    for (int i = 0; i < V; i++)
        visited[i] = false;

    //Now process all vertices in order defined by Stack;
    while (!Stack.empty())
    {
        // Pop a vertex from the Stack
        int v = Stack.top();
        Stack.pop();

        //Print Strongly connected components of the popped vertex
        if (visited[v] == false)
        {
            DFSUtil(v, visited);
            cout << endl;
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in given Graph \n";
    g.printSCCs();
    return 0;
}
>>>>>>> e494c07ad24dd4a5c0c1f04ca84f9f14fa7d3296
