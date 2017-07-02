//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define SIZE_M 27

using namespace std;

int n, matrix[SIZE_M][SIZE_M];
int visited[SIZE_M][SIZE_M];
int areaCount;
int T;

void readData()
{
	char newLine;
	char start;
	char end;
	char maxNode;

	maxNode = getchar();
	n = maxNode - 64;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++) {
			visited[i][j] = 0;
			matrix[i][j] = 0;

			if (i == j)
				matrix[i][j] = 1;
		}
	}
	while (true) {
		newLine = getchar();

		start = getchar();

		if (T)
		{
			if (start == '\n') break;
		}
		else
		{
			if ((start < 65 || start > 91) && start != '\n') break;
		}


		end = getchar();
		matrix[start - 65][end - 65] = 1;
		matrix[end - 65][start - 65] = 1;
	}



}

void printData()
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}
}

void FloodFill(int y)
{

	for (int i = 0;i < n;i++)
	{
		if (visited[y][i] == 0 && matrix[y][i] == 1)
		{
			visited[y][i] = 1;
			FloodFill(i);
		}
	}



}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> T;
	char newLine;
	newLine = getchar();
	newLine = getchar();
	while (T--)
	{
		areaCount = 0;
		readData();
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (visited[i][j] != 1 && matrix[i][j] == 1) {
					visited[i][j] = 1;
					FloodFill(j);
					areaCount++;
				}

			}
		}

		//printData();
		cout << areaCount << endl;
		if(T) cout << endl;
	}
	return 0;
}
