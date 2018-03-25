#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M,dist,B;
int x, y;
int points[11][2];
int visited[11];
int A[11];

void initialize() {
	dist = 9999999;
	for (int i = 0;i < 11;i++) {
		points[i][0] = points[i][1] = 0;
		visited[i] = 0;
		A[i] = 0;
	}
}

int abs(int x, int y) {
	if (x > y)
		return x - y;
	else
		return y - x;
}
void calDis() {
	int px=x, py=y;
	int d = 0;
	for (int i = 0;i < B;i++) {
		d = d + abs(points[A[i]][0], px) + abs(points[A[i]][1], py);
		px = points[A[i]][0];
		py = points[A[i]][1];
	}

	d = d + abs(px, x) + abs(py, y);

	if (d < dist)
		dist = d;
}
void solve(int i) {
	if (i == B) {
		calDis();
		return;
	}

	for (int j = 0;j < B;j++) {
		if (!visited[j]) {
			A[i] = j;
			visited[j] = 1;
			solve(i + 1);
			visited[j] = 0;
		}
	}
}
void readData() {
	cin >> N >> M;
	
	cin >> x >> y;
	cin >> B;

	for (int i = 0;i < B;i++) {
		cin >> points[i][0] >> points[i][1];
	}
}


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;
	
	while (T--) {
		initialize();
		readData();
		solve(0);
		cout << "The shortest path has length " << dist << endl;
	}
	return 0;
}

/*
input:
1
10 10
1 1
4
2 3
5 5
9 4
6 5

output:
The shortest path has length 24
*/