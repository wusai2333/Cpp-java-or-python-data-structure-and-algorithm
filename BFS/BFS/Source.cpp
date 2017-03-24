#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

struct Vertex
{
	vector<int> adj; //The adjacency list;
	int dist; //The distance from the source;
	int index; // the index of this vertex;
	int prev; // The index of the vertex previous in the path;
};

vector<Vertex*>	createGraph()
{
		
}

void BFSTraverse(vector<Vertex*> theGraph, int from)
{
	// Assume code to initialize all Vertices dist field to INFINITY
	queue<Vertex*> toExplore;
	Vertex* start = theGraph[from];
	start->dist = 0;
	toExplore.push(start);
	while (!toExplore.empty()) {
		Vertex* next = toExplore.front();
		toExplore.pop();
		vector<int>::iterator it = next->adj;
		for (; it != next.adj.end(); ++it) {
			Vertex* neighbor = theGraph[*it];
			if (next->dist + 1 < neighbor->dist) {
				neighbor->dist = next->dist + 1;
				neighbor->prev = next->index;
				toExplore.push(neighbor);
			}
		}
	}
}