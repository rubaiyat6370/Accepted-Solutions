#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

int N;
int coordinates[9][2];
int A[100];
int visited[100];
double distArray[9];
double minimum;
int minCoordinates[9][2];
double minDistArray[9];

void initVisited()
{
	for (int i = 0; i < N; i++)
	{
		visited[i] = 0;
		distArray[i] = 0;
		coordinates[i][0] = 0;
		coordinates[i][1] = 0;
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
	return sqrt(absolute(x1 - x2)*absolute(x1 - x2) + absolute(y1 - y2)*absolute(y1 - y2));
}


void sortedDistance()
{
	double sum = 0;
	for (int i = 0; i < N-1; i++)
	{
		distArray[i] = distance(coordinates[A[i]][0], coordinates[A[i]][1], coordinates[A[i + 1]][0], coordinates[A[i+1]][1]);
		sum += distArray[i] + 16;
	}

	if (sum < minimum)
	{
		minimum = sum;
		for (int i = 0; i < N; i++)
		{
			minDistArray[i] = distArray[i] + 16;
			minCoordinates[i][0] = coordinates[A[i]][0];
			minCoordinates[i][1] = coordinates[A[i]][1];
		}
	}
}

void print(int k)
{
	cout << "**********************************************************" << endl;
	cout << "Network #" << k << endl;
	for (int i = 0; i < N-1; i++)
	{
		cout << "Cable requirement to connect (" << minCoordinates[i][0] << "," << minCoordinates[i][1] << ") to (" << minCoordinates[i + 1][0] << "," << minCoordinates[i + 1][1] << ") is ";
		printf("%.2f feet.\n", minDistArray[i]);
	}
	printf("Number of feet of cable required is %.2f.\n", minimum);
}

void permutation(int i)
{
	if (i == N)
	{
		sortedDistance();
		return;
	}

	for (int j = 0; j < N; j++)
	{
		if (visited[j] == 0)
		{
			A[i] = j;
			visited[j] = 1;
			permutation(i + 1);
			visited[j] = 0;
		}

	}
}

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	initVisited();
	int k=1;
	while (cin >> N)
	{
		minimum = 9999;
		if (N)
		{
			for (int i = 0; i < N; i++)
			{
				cin >> coordinates[i][0] >> coordinates[i][1];
			}
			permutation(0);
			print(k);
		
		}
		else break;
		k++;
	}

	return 0;
}
