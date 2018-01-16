#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;

int input[100][100];
int visited[100][100];

const int R = 0;
const int L = 1;
const int U = 2;
const int D = 3;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int one[4] = { U,D,R,L };
int two[4] = { D,U,L,R };

void initData() {
	for (int i = 0;i < 100;i++) {
		for (int j = 0;j < 100;j++) {
			input[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void spiralRead() {
	for (int i = 0;i < N/2+1;i++) {
		int x = i;
		int y = i;

		if (visited[x][y] == 0) {
			cout << input[x][y] << endl;
			visited[x][y] = 1;
		}

		for (int m = 0;m < 4;m++) {

			for (int j = i+1;j < N - i;j++) {
				x = dx[m] + x;
				y = dy[m] + y;

				if (visited[x][y] == 0) {
					cout << input[x][y] << endl;
					visited[x][y] = 1;
				}

			}
		}
		
		
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

	spiralRead();

	//cout << mirror << endl;
	return 0;
}


/*
sample input
10
1  2  3  4  5  6  7  8  9  10
36 37 38 39 40 41 42 43 44 11
35 64 65 66 67 68 69 70 45 12
34 63 84 85 86 87 88 71 46 13
33 62 83 96 97 98 89 72 47 14
32 61 82 95 00 99 90 73 48 15
31 60 81 94 93 92 91 74 49 16
30 59 80 79 78 77 76 75 50 17
29 58 57 56 55 54 53 52 51 18
28 27 26 25 24 23 22 21 20 19
5
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

sample output
print numbers sequentially

*/
