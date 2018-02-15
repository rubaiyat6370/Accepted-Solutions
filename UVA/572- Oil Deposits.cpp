#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define MAX 101

using namespace std;

int grid[MAX][MAX];
int row, col;
int visited[MAX][MAX];


int areaCounter;

void initData() {

	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			grid[i][j] = 0;
			visited[i][j] = 0;
		}
		
	}
}

void connectedComponent(int x, int y) {
	visited[x][y] = 1;

	if (x + 1 < row && visited[x + 1][y] == 0 && grid[x + 1][y] == 1) {
		areaCounter++;
		connectedComponent(x + 1, y);
	}

	if (x - 1 >= 0 && visited[x - 1][y] == 0 && grid[x - 1][y] == 1) {
		areaCounter++;
		connectedComponent(x - 1, y);

	}

	if (y + 1 < col && visited[x][y + 1] == 0 && grid[x][y + 1] == 1) {
		areaCounter++;
		connectedComponent(x, y + 1);
	}

	if (y - 1 >= 0 && visited[x][y - 1] == 0 && grid[x][y - 1] == 1) {
		areaCounter++;
		connectedComponent(x, y - 1);
	}

	if (x + 1 < row && y + 1 < col && visited[x + 1][y + 1] == 0 && grid[x + 1][y + 1] == 1) {
		areaCounter++;
		connectedComponent(x + 1, y + 1);
	}
	if (x - 1 >= 0 && y - 1 >= 0 && visited[x - 1][y - 1] == 0 && grid[x - 1][y - 1] == 1) {
		areaCounter++;
		connectedComponent(x - 1, y - 1);
	}
	if (x + 1 < row && y - 1 >= 0 && visited[x + 1][y - 1] == 0 && grid[x + 1][y - 1] == 1) {
		areaCounter++;
		connectedComponent(x + 1, y - 1);
	}
	if (x - 1 >= 0 && y + 1 < col && visited[x - 1][y + 1] == 0 && grid[x - 1][y + 1] == 1) {
		areaCounter++;
		connectedComponent(x - 1, y + 1);
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
					connectedComponent(i, j);
					connectedComp++;
				}
			}
		}

		cout << connectedComp << endl;
	}
	return 0;
}
