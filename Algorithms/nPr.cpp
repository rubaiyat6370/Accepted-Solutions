#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
int N,r;
int A[100];
int input[100];
int visited[100];

void init()
{
	for (int i = 0;i < N;i++)
	{
		visited[i] = 0;
		input[i] = 0;
		A[i] = 0;
	}
}

void print()
{
	for (int i = 0;i < r;i++)
		cout << A[i];
	cout << endl;
}

void permutation(int level)
{
	if (level == r) {
		print();
		return;
	}
	int i;
	for (i = 0;i<N;i++) {
		if (visited[i] == 0)
		{
			A[level] = input[i];
			visited[i] = 1;
			permutation(level + 1);
			visited[i] = 0;
		}
	}
}

void readData()
{
	cin >> N >> r;

	for (int i = 0;i < N;i++)
	{
		cin >> input[i];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	init();
	readData();
	permutation(0);
	return 0;
}
