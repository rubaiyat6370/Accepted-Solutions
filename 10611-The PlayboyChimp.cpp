#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE_LADY 50001
#define SIZE_Q 25001

using namespace std;

int N, Q, Max, Min;
int lady[SIZE_LADY], Query[SIZE_Q];

void read()
{
	cin >> N;

	for (int i = 0;i < N;i++)
		cin >> lady[i];

	cin >> Q;

	for (int i = 0;i < Q;i++)
		cin >> Query[i];
}

void solve()
{
	for (int i = 0;i < Q;i++)
	{
		int height = Query[i];
		int minHeight = 0, maxHeight = 0;
		Max = 2147483647;
		Min = 2147483647;
		for (int j = 0;j < N;j++)
		{
			int diff = height - lady[j];
			if (diff > 0 && diff < Min && diff != 0)
			{
				Min = diff;
				minHeight = lady[j];
			}
			diff = lady[j] - height;
			if (diff > 0 && diff < Max && diff != 0)
			{
				Max = diff;
				maxHeight = lady[j];
			}
		}

		if (minHeight != 0)
			cout << minHeight;
		else cout << "X";
		cout << " ";
		if (maxHeight != 0)
			cout << maxHeight;
		else cout << "X";

		cout << endl;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	read();
	solve();
	return 0;
}
