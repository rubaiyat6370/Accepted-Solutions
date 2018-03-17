#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define size_n 1001
using namespace std;

int N, G,Ans;
int price[size_n];
int weight[size_n];
int dp[size_n][32];

void initDP() {
	for (int i = 0;i <= N;i++)
		for (int j = 0;j<=31;j++)
			dp[i][j] = -1;
}

int superSale(int i, int capacity) {
	int left, right;
	if (dp[i][capacity] >= 0)
		return dp[i][capacity];
	if (i == N) {
		
		return dp[i][capacity]= 0;
	}
	left = superSale(i + 1, capacity);

	if (weight[i] <= capacity) {
		right = price[i]+ superSale(i + 1, capacity - weight[i]);
	}
	else
		right = 0;
	if (left > right)
		return dp[i][capacity] = left;
	else
		return dp[i][capacity] = right;
	

}
void readData() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> price[i] >> weight[i];
	}

}

void solve() {
	int MG;
	Ans = 0;
	initDP();
	cin >> G;
	while (G--)
	{
		cin >> MG;
		Ans += superSale(0, MG);
	}
	cout << Ans << endl;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	for (int i = 0;i < T;i++) {
		readData();
		solve();
	}
	return 0;
}