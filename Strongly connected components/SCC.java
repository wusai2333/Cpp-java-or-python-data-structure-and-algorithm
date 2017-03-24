// Java implementation of kosaraju's algorithm to print all SCCs
import java.io.*;
import java.util.*;
import java.util.LinkedList;

// This class represents a directed graph using adjacency list representation
class Graph
{
    private int V; // No. of vertices
    private LinkedList<Integer> adj[]; // adjacency list

    //Constructor
    Graph(int v)
    {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < V; ++i)
            adj[i] = new LinkedList<Integer>();
    }

    // Function to add an edge into the Graph
    void addEdge(int v, int w) {adj[v].add(w);}

    //A recursive function to print DFS starting from v
    void DFSUtil(int v, boolean visited[])
    {
        // Mark the current node as vistied
        visited[v] = true;
        System.out.print(v + " ");

        // Recur for all the vertices adjacent to this vertex
        for (int i : adj[v])
        {
            if(!visited[i])
                DFSUtil(i, visited);
        }
    }

    //Function that returns reverse (or transpose) of this graph
    Graph getTranspose()
    {
        Graph g = new Graph(V);
        for (int v = 0; v < V; v++)
        {
            // Recur for all the vertices adjacent to this vertex
            for (int i : adj[v])
                g.adj[i].add(v);
        }
        return g;
    }

    void fillOrder(int v, boolean visited[], Stack<Integer> stack)
    {
        // Mark the current node as visited and print it
        visited[v] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int i : adj[v])
            if(!visited[i])
                fillOrder(i, visited, stack);
        // All vertices reachable from v are processed by now;
        // push v to stack;
        stack.push(v); //
    }

    // The main function that finds and prints all SCC
    void printSCCs()
    {
        Stack<Integer> stack = new Stack<Integer>();

        // Mark all the vertices as not visited(For first DFS)
        boolean visited[] = new boolean[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;

        // get the reversed Graph
        Graph gr = getTranspose();

        // Fill vertices in stack according to their finishing times
        for (int i = 0; i < V; i++)
            if(visited[i] == false)
                gr.fillOrder(i, visited, stack);

        // Mark all the vertices as not visited (for second DFS)
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Now process all vertices in order defined by Stack
        while (!stack.empty())
        {
            //Pop a vertex from stack
            int v = stack.pop();

            // Print SCC of the popped vertex
            if (visited[v] == false)
            {
                DFSUtil(v, visited);
                System.out.println();
            }
        }
    }

    //Driver method
    public static void main(String[] args)
    {
        // Create a graph in above diagram
        Graph g = new Graph(5);
        g.addEdge(1, 0);
        g.addEdge(0, 2);
        g.addEdge(2, 1);
        g.addEdge(0, 3);
        g.addEdge(3, 4);

        System.out.println("Following are strongly connected components in given graph ");

        g.printSCCs();
    }

}
