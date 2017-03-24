import java.util.Scanner;

public class BellmanFord
{
	private int distances[];
	private int numberOfVertices;
	public static final int MAX_VALUE = 9999;

	public BellmanFord(int numberOfVertices)
	{
		this.numberOfVertices = numberOfVertices;
		distances = new int[numberOfVertices+1];
	}


	public void BellmanFordEvaluation(int source, int adjacencymatrix[][])
	{
		for (int node = 1; node <= numberOfVertices; node++)
		{
			distances[node] = MAX_VALUE;
		}

		distances[source] = 0;
		for (int node = 1; node <= numberOfVertices - 1; node++)
		{
			for (int sourcenode = 1; sourcenode <= numberOfVertices; sourcenode++)
			{
				for (int destination = 1; destination <= numberOfVertices; destination++)
				{
					if (adjacencymatrix[sourcenode][destination] != MAX_VALUE) {
						if (distances[destination] > distances[sourcenode] + adjacencymatrix[sourcenode][destination]) {
							distances[destination] = distances[sourcenode] + adjacencymatrix[sourcenode][destination];
						}
					}
				}
			}
		}

		for (int sourcenode = 1; sourcenode <= numberOfVertices; sourcenode++)
		{
			for (int destination = 1; destination <= numberOfVertices; destination++)
			{
				if (adjacencymatrix[sourcenode][destination] != MAX_VALUE) {
					if (distances[destination] < distances[sourcenode] + adjacencymatrix[sourcenode][destination]) {
						System.out.println("The Graph contains negative edge cycle");
					}
				}
			}
		}
		for (int vertex = 1; vertex <= numberOfVertices; vertex++)
		{
			System.out.println("distance of source  " + source + " to " + vertex + " is " + distances[vertex]);
		}
	}


	public static void main(String[] args)
	{
		int numberOfVertices = 0;
		int source;
		Scanner scanner = new Scanner(System.in);

		System.out.println("Enter the number of vertices");
		numberOfVertices = scanner.nextInt();

		int adjacencymatrix[][] = new int[numberOfVertices+1][numberOfVertices+1];
		System.out.println("Enter the adjacency matrix");
		for (int sourcenode = 1; sourcenode <= numberOfVertices; sourcenode++)
		{
			for (int destination = 1; destination <= numberOfVertices; destination++)
			{
				adjacencymatrix[sourcenode][destination] = scanner.nextInt();
				if (sourcenode == destination) {
					adjacencymatrix[sourcenode][destination] = 0;
					continue;
				}
				if (adjacencymatrix[sourcenode][destination] == 0) {
					adjacencymatrix[sourcenode][destination] = MAX_VALUE;
				}
			}
		}

		System.out.println("Enter the source vertex");
		source = scanner.nextInt();

		BellmanFord bellmanford = new BellmanFord(numberOfVertices);
		bellmanford.BellmanFordEvaluation(source, adjacencymatrix);
		scanner.close();
	}
}
