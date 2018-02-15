#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define MAX 101

using namespace std;

int grid[MAX][MAX];
int row, col;
int visited[MAX][MAX];

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };


int areaCounter;

void initData() {

	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			grid[i][j] = 0;
			visited[i][j] = 0;
		}

	}
}

int isValid(int x, int y) {
	if (x < 0 || y < 0 || x >= row || y >= col) return 0;
	else return 1;
}

void floodFill(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0;i < 8;i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (isValid(xx, yy)==1 && visited[xx][yy] == 0 && grid[xx][yy] == 1) {
			areaCounter++;
			floodFill(xx, yy);
		}
	}
}


int main() {

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> row >> col) {
		if (row == 0) break;
		initData();
		char c;
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				cin >> c;
				if (c == '*') grid[i][j] = 0;
				if (c == '@') grid[i][j] = 1;
			}
		}
		int connectedComp = 0;
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				if (visited[i][j] == 0 && grid[i][j] == 1) {
					//connectedComponent(i, j);
					floodFill(i, j);
					connectedComp++;
				}
			}
		}

		cout << connectedComp << endl;
	}
	return 0;
}
