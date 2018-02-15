#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define SIZE_M 1001

using namespace std;

int n, matrix[SIZE_M][SIZE_M];
int visited[SIZE_M][SIZE_M];
int area[SIZE_M];
int areaCount;
int counter;
int T,A,B,C;

void readData()
{

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++) {
			visited[i][j] = 0;
		}
		area[i] = 0;
	}
	
	for (int i = 0;i < n;i++)
	{
		char c;
		cin.get(c);
		for (int j = 0;j < n;j++) {
			c = getchar();
			matrix[i][j] = c - 48;
		}
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



void FloodFill(int x,int y)
{

	if (x + 1 < n && matrix[x + 1][y] == 1 && visited[x + 1][y] == 0)
	{
		visited[x + 1][y] = 1;
		counter++;
		FloodFill(x + 1, y);
	}

	if (x - 1 >= 0 && matrix[x - 1][y] == 1 && visited[x - 1][y] == 0)
	{
		visited[x - 1][y] = 1;
		counter++;
		FloodFill(x - 1, y);
	}

	if (y + 1 < n && matrix[x][y+1] == 1 && visited[x][y+1] == 0)
	{
		visited[x][y+1] = 1;
		counter++;
		FloodFill(x, y+1);
	}

	if (y - 1 >= 0 && matrix[x ][y-1] == 1 && visited[x][y-1] == 0)
	{
		visited[x][y-1] = 1;
		counter++;
		FloodFill(x, y-1);
	}

	if (x + 1 < n && y + 1 < n && matrix[x + 1][y + 1] == 1 && visited[x + 1][y + 1] == 0)
	{
		visited[x + 1][y + 1] = 1;
		counter++;
		FloodFill(x + 1, y + 1);
	}

	if (x - 1 >= 0 && y + 1 < n && matrix[x - 1][y + 1] == 1 && visited[x - 1][y + 1] == 0)
	{
		visited[x - 1][y + 1] = 1;
		counter++;
		FloodFill(x - 1, y + 1);
	}

	if (x + 1 < n && y - 1 >= 0 && matrix[x + 1][y - 1] == 1 && visited[x + 1][y - 1] == 0)
	{
		visited[x + 1][y - 1] = 1;
		counter++;
		FloodFill(x + 1, y - 1);
	}

	if (x - 1 >= 0 && y - 1 >= 0 && matrix[x - 1][y - 1] == 1 && visited[x - 1][y - 1] == 0)
	{
		visited[x - 1][y - 1] = 1;
		counter++;
		FloodFill(x - 1, y - 1);
	}


}

void sort()
{
	for (int i = 0;i < areaCount;i++)
	{
		for (int j = i+1;j < areaCount;j++)
		{
			if (area[i] < area[j])
			{
				int temp = area[j];
				area[j] = area[i];
				area[i] = temp;
			}
		}
	}
}

void printResult()
{
	for (int i = 0;i < areaCount;i++)
		cout << "area[" << i << "] :" << area[i] << endl ;
	cout << endl;

	A = B = C = 0;
	for (int i = 0;i < areaCount;i++)
	{
		A += area[i];
		i++;
		B += area[i];
		i++;
		C += area[i];
	}

	cout << "A :" << A << endl;
	cout << "B :" << B << endl;
	cout << "C :" << C << endl << endl;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (cin >> n)
	{
		if(n!=0)
		{ 
			readData();
			//printData();
			areaCount = 0;
			for (int i = 0;i < n;i++)
			{
				counter = 0;
				for (int j = 0;j < n;j++)
				{
					if (visited[i][j] == 0 && matrix[i][j] == 1) {
						visited[i][j] = 1;
						counter++;
						FloodFill(i, j);
						area[areaCount] = counter;
						areaCount++;
					}

				}
			}
			sort();
			printResult();
			//cout << sqrt(121) << endl;
		}
		else break;
		
		

	}
	return 0;
}
