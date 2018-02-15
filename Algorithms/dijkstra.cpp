#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define S 27

using namespace std;

int weight[S][S];
int input[S][S];
int vis[S];
char path[S];
int n, m, index;

void initData() {
	index = 0;
	for (int i = 0;i < S;i++) {
		for (int j = 0;j < S;j++) {
			input[i][j] = 0;
			weight[i][j] = 99999999;
		}
		path[i] = ' ';
		vis[i] = 1;
	}
}

void dijkstra(int x, int prev, int minw) {
	
	vis[x] = 0;
	path[index++] = x + 64;
	
	int minimum = 99999999;
	int temw;
	for (int i = 1;i <= m;i++) {
		if (input[x][i] != 0 && (minw+input[x][i]<weight[prev][i])) {
			weight[x][i] = minw + input[x][i];
		}
		else {
			weight[x][i] = weight[prev][i];
		}

		if (weight[x][i] <= minimum && vis[i]==1) {
			minimum = weight[x][i];
			temw = i;
		}
	}

	if (minimum < 99999999) {
		dijkstra(temw, x, minimum);
	}
}

int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> m >> n;
	char a,b;
	initData();
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		cin >> input[a - 64][b - 64];
		input[b - 64][a - 64] = input[a - 64][b - 64];
	}
	weight[0][1] = 0;
	dijkstra(1, 0, 0);
	

	return 0;
}
