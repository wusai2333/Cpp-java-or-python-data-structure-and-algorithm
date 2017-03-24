#python program to print DFS
from collections import defaultdict
#This class represents a directed graph using adjcency
#list representation
class Graph:
    def __init__(self):
        #default dictionary to stor graph
        self.graph = defaultdict(list)

    # function to add and edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)

    # A function used by DFS
    def DFSUtil(self, v, visited):
        # Mark the current node as visited
        visited[v] = True
        print (v, end=" ")

        # Recur for all the vertices adjacent to this vertex
        for i in self.graph[v]:
            if visited[i] == False:
                self.DFSUtil(i, visited)

    # The function to do DFS traversal. It uses recursive DFSUtil()
    def DFS(self):
        V = len(self.graph)

        # Mark all the vertices as not visited
        visited = [False]*V
        # Call the recursive helper function to print DFS traversal
        # starting from all vertices on by one
        for v in self.graph:
            if visited[v] == False:
                self.DFSUtil(v, visited)

#Driver code
# Create a graph given in th above diagram
g = Graph();
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)
print("Following is DFS")
g.DFS()
