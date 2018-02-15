#define _CRT_SECURE_NO_WARNINGS
#define SIZE_N 10001
#include <iostream>

using namespace std;

int a, b, c, d, e, f, n;
int DP[SIZE_N];

void initDP()
{
	for (int i = 0;i <= n;i++)
		DP[i] = -1;
}

void read()
{
	cin >> a >> b >> c >> d >> e >> f >> n;
}

int fn(int n) {

	if (DP[n] != -1)
		return DP[n];
	if (n == 0) return DP[n] = a;
	if (n == 1) return DP[n] = b;
	if (n == 2) return DP[n] = c;
	if (n == 3) return DP[n] = d;
	if (n == 4) return DP[n] = e;
	if (n == 5) return DP[n] = f;
	return DP[n] = ((fn(n - 1)% 10000007) + (fn(n - 2)% 10000007) + (fn(n - 3)% 10000007) + (fn(n - 4)% 10000007) + (fn(n - 5)% 10000007) + (fn(n - 6)% 10000007))% 10000007;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;

	cin >> T;

	for(int i=0;i<T;i++)
	{
		read();
		initDP();
		cout << "Case " << i+1 << ": " << fn(n) % 10000007 << endl;
	}
	return 0;
}
