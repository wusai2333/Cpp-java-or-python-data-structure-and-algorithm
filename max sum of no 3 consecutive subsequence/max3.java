<<<<<<< HEAD
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
class max3 {
	private static int max_three(int[] input, int N)
	{
		int sum[] = new int [N + 1];

		sum [0] = 0;
		sum [1] = input [0];
		sum [2] = input [0] + input [1];
		for (int i = 2; i < N; ++i)
		{
			sum [i + 1] = Math.max(input [i] + sum [i - 1], input [i] + input [i - 1] + sum [i - 2]);
			sum [i + 1] = Math.max(sum [i + 1], sum [i]);
		}

		return (sum [N]);
	}


	public static void main(String[] args)
	{
		int[] input =
		{
			1, 2, 3, 4, 5
		};
		int N = input.length;
		int sum = max_three(input, N);
		System.out.print(sum);
	}
}
=======
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
class max3 {
	private static int max_three(int[] input, int N)
	{
		int sum[] = new int [N + 1];

		sum [0] = 0;
		sum [1] = input [0];
		sum [2] = input [0] + input [1];
		for (int i = 2; i < N; ++i)
		{
			sum [i + 1] = Math.max(input [i] + sum [i - 1], input [i] + input [i - 1] + sum [i - 2]);
			sum [i + 1] = Math.max(sum [i + 1], sum [i]);
		}

		return (sum [N]);
	}


	public static void main(String[] args)
	{
		int[] input =
		{
			1, 2, 3, 4, 5
		};
		int N = input.length;
		int sum = max_three(input, N);
		System.out.print(sum);
	}
}
>>>>>>> e494c07ad24dd4a5c0c1f04ca84f9f14fa7d3296
