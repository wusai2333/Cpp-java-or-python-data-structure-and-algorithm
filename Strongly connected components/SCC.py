# Python implementation of kosaraju's algorithm to print all SCCs
from collections import defaultdict

#This class represents a directed graph using adjacency list representation
class Graph:

    def __init__(self, vertices):
        self.V = vertices #no. of vertices
        self.graph = defaultdict(list) # default dictionary to store graph

    # Function to add an edge to graph
    def addEdge(self, u ,v):
        self.graph[u].append(v)
    # A function used by DFS
    def DFSUtil(self, v, visited):
        #Mark the current node as visited and print it
        visited[v] = True;
        print(v, end=' ')
        # Recur for all the vertices adjacent to this vertex
        for i in self.graph[v]:
            if visited[i] == False:
                self.DFSUtil(i, visited)

    def fillOrder(self, v, visited, stack):
        # Mark the current node as visited
        visited[v] = True;
        # Recur for all the vertices adjacent to this vertex
        for i in self.graph[v]:
            if visited[v] == False:
                self.fillOrder(i, visited, stack)
        stack = stack.append(v)

    # Function that returns reverse (or transpose) of this graph
    def getTranspose(self):
        g = Graph(self.V)
        # Recur for all the vertices adjacent to this vertex
        for i in self.graph:
            for j in self.graph[i]:
                g.addEdge(j, i)
        return g

    # The main function that finds and return all SCC
    def printSCCs(self):

        stack = []
        visited = [False]*(self.V)

        # Create a reversed graph
        gr = self.getTranspose()

        # Fill vertices in stack according to their postnumber
        for i in range(self.V):
            if visited[i] == False:
                gr.fillOrder(i, visited, stack)

        #Mark all the vertices as not visited(For second DFS)
        visited = [False]*(self.V)

        # Now process all vertices in order defined by stack
        while stack:
            i = stack.pop()
            if visited[i] == False:
                self.DFSUtil(i, visited)
                print("");
# Create a graph given in the above diagram
g = Graph(5)
g.addEdge(1, 0)
g.addEdge(0, 2)
g.addEdge(2, 1)
g.addEdge(0, 3)
g.addEdge(3, 4)

print("Following are strongly connected components in given graph")
g.printSCCs()
