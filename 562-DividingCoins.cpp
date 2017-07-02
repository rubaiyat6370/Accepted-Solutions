#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define SIZE 101
#define SIZE_SUM 50001
using namespace std;

int n,total, input[SIZE], binary[SIZE];
int minimum;
int DP[SIZE][SIZE_SUM];

void read()
{
	total = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		total += input[i];
	}

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j<SIZE_SUM; j++)
			DP[i][j] = -1;
}

int abs(int sum1, int sum2)
{
	if (sum1 > sum2)
		return sum1 - sum2;
	else return sum2 - sum1;
}

void solve(int i, int sum1)
{
	if (DP[i][sum1] > 0)
		return;

	if (i == n)
	{
		int sum2 = total - sum1;
		int diff = abs(sum1, sum2);
		if (diff < minimum)
			minimum = diff;
		//cout << min << endl;
		return;
	}

	//binary[i] = 0;
	solve(i + 1,sum1);

	solve(i + 1, sum1 + input[i]);
	
	DP[i][sum1] = 1;
	//return DP[i][sum1];
}

int main()
{
	int T, test_case;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> T;
	
	for (test_case = 0; test_case < T; test_case++)
	{
		minimum = 9999;
		cin >> n;
		read();
		solve(0,0);
		cout << minimum << endl;
	}
	return 0;
}
