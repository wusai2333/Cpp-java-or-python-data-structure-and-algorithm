// C++ program to find out maximum profit by buying and 
// selling a share at most k times given stock
// price of n days
#include <iostream>
#include <climits>
#include <algorithm>
#include <minmax.h>
#include <Windows.h>
#include <memory>
#include <vector>
using namespace std;

// Function to store results of subproblems
// profits[t][i] stores maximum profit using
// atmost t transactions up to day i;(include day i);
int maxProfit(int price[], int n,int k)
{
	// table to store results of subproblems
	// profit[t][i] stores maximum profit using atmost t
	// transactions up to day i(including day i)
	vector <vector<int> > profit(k+1);
	for (int i = 0; i < k + 1; i++)
		profit[i].resize(n + 1);
	// For day 0 you can't earn money
	// irrespective of how many times you trade
	for (int i = 0; i <= k; i++)
		profit[i][0] = 0;
	// Profit is 0 if we don't make any transaction
	// (i.e k = 0);
	for (int i = 0; i <= n; i++)
		profit[0][i] = 0;

	//fill the table in bottom-up fashion
	for (int i = 1; i <= k; i++)
	{	
		int preDiff = INT_MIN; // optimized part;
		for (int j = 1; j <= n; j++)
		{
			//int max_so_far = INT_MIN;
			preDiff = max(preDiff, profit[i - 1][j - 1] - price[j - 1]);
			profit[i][j] = max(profit[i][j - 1], price[j] + preDiff);
			//for (int m = 0; m < j; m++) {
				//max_so_far = max(max_so_far, price[j] - price[m] + profit[i-1][m]);
				
			//}
			//profit[i][j] = max(profit[i][j-1], max_so_far);
		}
	}
	return profit[k][n];
}


// Driver Mode
int main()
{
	int k;
	cout << "enter k:";
	cin >> k;
	cout << "k = " << k << endl;
	int price[] = { 10, 22, 5, 75, 65, 80 };
	const int n = sizeof(price) / sizeof(price[0]);

	cout << "Maximum profit is: " << maxProfit(price, n, k) << endl;

	return 0;
	getchar();
}
