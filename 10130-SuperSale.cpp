#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#define SIZE_M 1001
#define SIZE_G 101
#define SIZE_DP 31

using namespace std;

int N, price[SIZE_M], weight[SIZE_M], P, MW[SIZE_G];
int maximal;
int maxPriceSum;
int DP[SIZE_M][SIZE_DP];

void initDP(int capacity)
{
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= capacity; j++)
			DP[i][j] = -1;
}

void read()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> price[i];
		cin >> weight[i];
	}

	cin >> P;

	for (int i = 0; i < P; i++)
	{
		cin >> MW[i];
	}


}

int solve(int i, int weightSum, int capacity)
{
	int left, right;

	if (DP[i][weightSum] != -1)
	{

		return DP[i][weightSum];
	}

	if (i == N)
	{
		return DP[i][weightSum] = 0;
	}

	left = solve(i + 1, weightSum, capacity);

	if (weightSum + weight[i] > capacity)
	{
		right = 0;
	}
	else
		right = price[i] + solve(i + 1, weightSum + weight[i], capacity);

	if (left > right)
		return DP[i][weightSum] = left;

	else return DP[i][weightSum] = right;

	
}

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		read();
		maxPriceSum = 0;
		for (int i = 0; i < P; i++)
		{
			initDP(MW[i]);
			maximal = 0;
			maximal = solve(0, 0, MW[i]);

			maxPriceSum += maximal;

		}

		cout << maxPriceSum << endl;

	}
	return 0;
}
