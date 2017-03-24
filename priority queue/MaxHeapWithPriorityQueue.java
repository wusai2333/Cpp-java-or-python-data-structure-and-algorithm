import java.util.PriorityQueue;
public class MaxHeapWithPriorityQueue {
	public static void main(String[] args)
	{
		// create PriorityQueue
		PriorityQueue<Integer> prq = new PriorityQueue<>((x, y) - > y - x);

		//insert values in the queue
		prq.add(6);
		prq.add(7);
		prq.add(6);
		prq.add(9);
		prq.add(15);

		// print values
		while (!prq.isEmpty())
		{
			System.out.println(prq.poll() + " ");
		}
	}
}
