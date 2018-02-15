#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE_M 21

using namespace std;
int sizeOfWorld[2];
int start[2];
int A[SIZE_M];
int visited[SIZE_M];
int coordinates[SIZE_M][2];
int minimum,N;

void initFields()
{
	sizeOfWorld[0] = 0;
	sizeOfWorld[1] = 0;
	minimum = 9999;

	for (int i = 0; i < N; i++)
	{
		A[i] = 0;
		visited[i] = 0;
		coordinates[i][0] = 0;
		coordinates[i][1] = 0;
	}
	
}

void readData()
{
	cin >> sizeOfWorld[0] >> sizeOfWorld[1];

	cin >> start[0] >> start[1];

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> coordinates[i][0] >> coordinates[i][1];
	}
}

double absolute(double i)
{
	if (i > 0)
		return i;
	else return -i;
}

double distance(int x1, int y1, int x2, int y2)
{
	return (absolute(x1 - x2) + absolute(y1 - y2));
}

void findShortestPath()
{
	double sum = distance(start[0], start[1], coordinates[A[0]][0], coordinates[A[0]][1]);
	int i;
	for (i = 0; i < N-1; i++)
	{
		sum += distance(coordinates[A[i]][0], coordinates[A[i]][1], coordinates[A[i+1]][0], coordinates[A[i+1]][1]);
	}

	sum += distance(coordinates[A[i]][0], coordinates[A[i]][1], start[0], start[1]);

	if (sum < minimum)
		minimum = sum;
}

void printData()
{
	cout << "The shortest path has length " << minimum << endl;
}

void permutation(int i)
{
	if (i == N)
	{
		findShortestPath();
		return;
	}

	for (int j = 0; j < N; j++)
	{
		if (visited[j] == 0)
		{
			visited[j] = 1;
			A[i] = j;
			permutation(i + 1);
			visited[j] = 0;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;

	while (T--)
	{
		initFields();
		readData();
		permutation(0);
		printData();
	}
	return 0;
}
