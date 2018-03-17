#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define size_n 1001
using namespace std;

int N, M;
int task[102][102];
int visited[102];

void initData() {
	for (int i = 0;i <= N;i++) {
		for (int j = 0;j <= N;j++) {
			task[i][j] = -1;
		}
		visited[i] = 0;
	}
}


void readData() {
	int a, b;

	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		task[a][b] = 1;
		visited[b]++;
	}

}

void solve() {
	int b = true;
	for (int i = 1;i <= N;i++) {
		if (visited[i]==0)
			cout << i << " ";
		else
			b = false;
	}

	if (!b) {
		while (!b) {
			b = true;
			for (int i = 1;i <= N;i++) {
				if (visited[i] == 0) {
					for (int j = 1;j <= N;j++) {
						if (visited[j] == 1) {
							cout << j << " ";
							visited[j]--;
						}
						else if (visited[j] > 1) {
							visited[j]--;
							b = false;
						}

					}
				}
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N >> M) {
		if (N == 0 && M == 0)
			break;
		initData();
		readData();
		solve();
		cout << endl;
	}
	return 0;
}