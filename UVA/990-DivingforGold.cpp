#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE_N 31
#define SIZE_t 1001

using namespace std;

int t, w, n, Ans, maximum;
int binary[SIZE_N];
int isFirst;
int flag[SIZE_N];
int depth[SIZE_N], quantity[SIZE_N];

void read()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> depth[i] >> quantity[i];
		//[i] = -1;
	}

}

void print()
{
	if (!isFirst)
		cout << endl; // This print new line sent me to hell!!!!!
	else isFirst = 0;
	cout << maximum << endl;
	int countTreasure = 0;
	for (int i = 0; i < n; i++)
	{
		if (flag[i] == 1)
			countTreasure++;
	}
	cout << countTreasure << endl;
	for (int i = 0; i < n; i++)
		if (flag[i] == 1)
			cout << depth[i] << " " << quantity[i] << endl;
}

void solve(int i, int depthSum, int goldSum)
{

	if (i == n)
	{
		if (goldSum > maximum)
		{
			maximum = goldSum;
			for (int j = 0; j < n; j++)
				flag[j] = binary[j];
		}
		return;
	}
	binary[i] = 0;
	solve(i + 1, depthSum, goldSum);

	binary[i] = 1;
	if (depthSum + 3 * w*depth[i] <= t)
	{
		solve(i + 1, depthSum + 3 * w*depth[i], goldSum + quantity[i]);

	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	isFirst = 1;
	while (cin >> t >> w)
	{
		maximum = 0;
		read();
		solve(0, 0, 0);
		print();
	}
	return 0;
}

/**
input:

974 4
17
16 27
20 30
19 44
10 46
12 30
13 45
17 40
12 13
5 12
19 45
12 11
17 8
5 40
4 8
17 26
8 22
3 36

output:

286
8
10 46
13 45
17 40
5 12
19 45
5 40
8 22
3 36


**/
