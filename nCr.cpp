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

void combination(int level,int pos)
{
	if (level == r) {
		print();
		return;
	}
	int i;
	for (i = pos;i<N;i++) {
		A[level] = input[i];
		combination(level + 1, i+1);
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
	combination(0,0);
	return 0;
}
