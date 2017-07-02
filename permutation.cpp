#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int N;
int A[100];
int visited[100];

void initVisited()
{
	for (int i = 0; i < N; i++)
		visited[i] = 0;
}

void print()
{
	/** (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (A[i] == A[j])
				return;
				**/

	for (int i = 0; i < N; i++)
		cout << A[i];
	cout << endl;
}

int check(int i, int j)
{
	for (int k = 0; k < i; k++)
		if (A[k] == j)
			return 1;
	return 0;
}
void solve(int i)
{
	//cout << "Solve(" << i << ") starts" << endl;
	if (i == N)
	{
		print();
		return;
	}

	for (int j = 0; j < N; j++)
	{
		if (visited[j] == 0)
		{
			A[i] = j;
			visited[j] = 1;
			solve(i + 1);
			visited[j] = 0;
		}
	}

	//cout << "Solve(" << i << ") ends" << endl;
}
int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	initVisited();
	cin >> N;
	solve(0);
	return 0;
}
