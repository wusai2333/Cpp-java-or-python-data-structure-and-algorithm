//Program to print BFS traversal from a given source vertex. BFS(int s) traverses vertices reachable from s
#include <iostream>
#include <list>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph
{
	int V;                          // No. of vertices
	list<int> *adj;                 // Pointer to an array con taining adjacency lists
public:
	Graph(int V);                   // Constructor
	void addEdge(int v, int w);     // function to add an edge to graph
	void BFS(int s);                // prints BFS traversal from a given source s
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}


void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}


void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	// Create a queue for BFS
	list<int> queue;

	//Mark the current node as visited and enqueue it
	//for (int i = 0; i < V; i++)
	//{

	/*if(visited[i] == false) {
	 *  visited[i] = true;
	 *  queue.push_back(i);
	 * }
	 * else
	 *  continue;
	 */
	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		int i = queue.front();
		cout << i << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it as visited and enqueue it
		for (auto v : adj[i])
		{
			if (!visited[v]) {
				visited[v] = true;
				queue.push_back(v);
			}
		}
	}
	//cout << endl;
	//}
}


// Driver method
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Search traversal (starting at vertex 3) \n";

	g.BFS(0);

	return (0);
}
