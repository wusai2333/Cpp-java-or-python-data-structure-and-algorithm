// A C / C++ program for Bellman-Ford's single source shortest
// path algorithm.

#include <cstdio>
#include <climits>
#include <vector>
#include <list>
#include <utility>

using namespace std;

void PrintNegativeCycle(vector<pair<int, int> > shortestDistances, int vertex, int startVertex)
{
	if (vertex == startVertex) {
		printf("%d ", vertex);
	} else if (shortestDistances[vertex].second == 0) {
		PrintNegativeCycle(shortestDistances, startVertex, startVertex);
		printf("%d ", vertex);
	} else {
		PrintNegativeCycle(shortestDistances, shortestDistances[vertex].second, startVertex);
		printf("%d ", vertex);
	}
}


// Bellman-Ford algorithm which takes the Adjacency List, starting vertex, and
// an empty shortestDistances vector as input. It applies the algorithm and keeps
// filling values into shortestDistances which is a reference parameter. It
// returns true if there are no negative edges, and vice-versa.

int bellmanFord(
	vector<list<pair<int, int> > > adjacencyList,
	int vertices,
	int startVertex,
	vector<pair<int, int> >& shortestDistances
	)
{
	list<pair<int, int> >::iterator traverse;
	int i, j, k;

	// Initialisation
	for (i = 1; i <= vertices; ++i)
	{
		shortestDistances[i].first = INT_MAX;
		shortestDistances[i].second = -1;
	}
	// Set distance to source = 0
	shortestDistances[startVertex].first = 0;
	shortestDistances[startVertex].second = 0;

	// The algorithm that computes Shortest Distances
	for (i = 1; i <= vertices - 1; ++i)                     // Run 'vertices - 1' times = O(V)
	{
		for (j = 1; j <= vertices; ++j)                 // Run as many times as the edges = O(E)
		{                                               // The code ahead basically explores the whole of adjacencyList,
			// covering one edge once, so that the runtime of the code in this block
			// is O(E)

			traverse = adjacencyList[j].begin();

			while (traverse != adjacencyList[j].end())
			{
				if (shortestDistances[j].first == INT_MAX) {
					// Important...!
					// Traverse =  trverse.next;
					++traverse;
					continue;
				}

				// Check for relaxation
				if ((*traverse).second + shortestDistances[j].first < shortestDistances[(*traverse).first].first) {
					// relaxation
					shortestDistances[(*traverse).first].first = (*traverse).second + shortestDistances[j].first;
					shortestDistances[(*traverse).first].second = j;
				}

				++traverse;
			}
		}
	}

	// Checking for Negative Cycles
	for (j = 1; j <= vertices; ++j)
	{
		traverse = adjacencyList[j].begin();

		while (traverse != adjacencyList[j].end())
		{
			// Checking for further relaxation
			if ((*traverse).second + shortestDistances[j].first <
			    shortestDistances[(*traverse).first].first) {
				// Negative cycle found as further relaxation is possible
				return (j);
			}
			++traverse;
		}
	}
	return (-1);
} // bellmanFord


int main()
{
	int vertices, edges, v1, v2, weight;

	printf("Enter the Number of Vertices - \n");
	scanf("%d", &vertices);

	printf("Enter the Number of Edges -\n");
	scanf("%d", &edges);

	// Adjacency List is a vector of list.
	// Where each element is pair <int, int>
	// pair.first -> the edges's destination
	// pair.second -> edge's weight
	vector<list<pair<int, int> > > adjacencyList(vertices + 1);

	printf("Enter the Edges V1 -> V2, of weight W\n");

	for (int i = 1; i <= edges; ++i)
	{
		scanf("%d%d%d", &v1, &v2, &weight);

		// Adding Edge to the Direct Graph
		adjacencyList[v1].push_back(make_pair(v2, weight));
	}

	printf("\nThe Adjacency List-\n");
	// Printing the Adjacency List
	for (int i = 1; i < adjacencyList.size(); ++i)
	{
		printf("adjacencyList[%d] ", i);

		for (auto itr : adjacencyList[i])
		{
			printf(" -> %d(%d)", itr.first, itr.second);
		}
		printf("\n");
	}

	vector<pair<int, int> > shortestDistances(vertices + 1);
	// shortestDistances is a vector of pairs
	// pairs.first -> the shortestDistance from startVertex
	// pairs.second -> parent vertex in the shortest path

	int startVertex;

	printf("\nEnter the Start Vertex -\n");
	scanf("%d", &startVertex);

	int returnValue = bellmanFord(adjacencyList, vertices, startVertex, shortestDistances);

	if (returnValue == -1) {
		printf("No negative cycles exist in the graph - \n");
	} else {
		printf("Negative cycles exist in the graph -\n");
		// The Bellman-Ford algorithm does not work with negative cycles,
		// all it can do is merely detect them, so when a negative cycles
		// is detected, the shortestDistances vector has wrong values;

		PrintNegativeCycle(shortestDistances, shortestDistances[returnValue].second, returnValue);

		return (0);
	}

	printf("\n\nVertex      Shortest Distance to Vertex %d      Parent Vertex-\n", startVertex);
	for (int i = 1; i <= vertices; ++i)
	{
		printf("%d \t  %d \t\t\t\t   %d\n", i, shortestDistances[i].first, shortestDistances[i].second);
	}

	return (0);
} // main
