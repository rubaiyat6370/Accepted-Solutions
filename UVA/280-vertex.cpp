#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int N,S;
int path[102][102];
int output[102];

void initialize()
{
	
	for (int i = 0;i < 102;i++)
	{
		for (int j = 0;j < 102;j++) {
			path[i][j] = 999999;
		}
		output[i] = 0;
	}
	
}

void readData() {
	int x, y;

	while (cin >> x && x) {
		while (cin >> y && y) {
			path[x][y] = 1;
		}
	}
}

void findAllPath() {

	for (int k = 1;k <= N;k++) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (path[i][j] > path[i][k] + path[k][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}
}
int findVertex(int x) {
	int t = 0;
	for (int i = 1;i <= N;i++) {
		if (path[x][i] == 999999) {
			output[t] = i;
			t++;
		}
	}
	return t;
}

void print(int t) {
	for (int i = 0;i < t;i++)
	{
		cout << " " << output[i];
	}
	cout << endl;
}

void solve() {
	cin >> S;
	int x;

	while (S--) {
		cin >> x;
		int t = findVertex(x);
		
		cout << t;
		print(t);
	}
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	while (cin >> N) {
		if (!N)
			break;
		
		initialize();
		readData();
		findAllPath();
		solve();
	}
	return 0;
}
/*
input:
3
1 2 0
2 2 0
3 1 2 0
0
2 1 2
0

output:
2 1 3
2 1 3
*/