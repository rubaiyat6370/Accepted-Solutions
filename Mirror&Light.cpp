#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;
int top;
int mirror;

int input[100][100];

const int R = 0;
const int L = 1;
const int U = 2;
const int D = 3;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int one[4] = { U,D,R,L };
int two[4] = { D,U,L,R };

void initData() {
	for (int i = 0;i < 100;i++) {
		for (int j = 0;j < 100;j++) {
			input[i][j] = 0;
		}
	}
}

int isValid(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N) {
		return 0;
	}
	return 1;
}

void countMirror(int x, int y, int d) {
	while (1) {

		if (isValid(x, y)) {
			if (input[x][y] > 0) {
				if (input[x][y] == 1) {
					mirror++;
					d = one[d];
				}
				if (input[x][y] == 2) {
					mirror++;
					d = two[d];

				}
			}
		}
		else
			return;
		x = x + dx[d];
		y = y + dy[d];

	}
}

int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> input[i][j];
		}
	}

	mirror = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (input[i][j] > 0) {
				//mirror++;
				countMirror(i, j, R);
				break;
			}
		}
		break;
	}

	cout << mirror << endl;
	return 0;
}


/*
sample input
10
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
10
0 0 0 0 0 0 0 2 0 0
0 0 0 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

sample output
1
3

*/
