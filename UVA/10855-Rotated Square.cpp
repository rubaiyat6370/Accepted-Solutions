#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

char inputN[1001][1001];
char inputn[1001][1001];
char rotated90[1001][1001];
char rotated180[1001][1001];
char rotated270[1001][1001];

int N, n;
int one, two, three, four;

void initData() {
	one = two = three = four = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			inputN[i][j] = ' ';
			inputn[i][j] = ' ';
			rotated90[i][j] = ' ';
			rotated180[i][j] = ' ';
			rotated270[i][j] = ' ';
		}
	}
}

void rotateMatrix() {
	int col = n;
	int row = n;
	int x = 0;
	for (int i = 0;i < col;i++) {
		int y = 0;
		for (int j = row - 1;j >= 0;j--) {
			rotated90[x][y] = inputn[j][i];
			y++;
		}
		x++;
	}

	x = 0;
	for (int i = 0;i < col;i++) {
		int y = 0;
		for (int j = row - 1;j >= 0;j--) {
			rotated180[x][y] = rotated90[j][i];
			y++;
		}
		x++;
	}

	x = 0;
	for (int i = 0;i < col;i++) {
		int y = 0;
		for (int j = row - 1;j >= 0;j--) {
			rotated270[x][y] = rotated180[j][i];
			y++;
		}
		x++;
	}
	
}

void cal() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int flag = 1;
			for (int x = 0;x < n;x++) {
				for (int y = 0;y < n;y++) {
					if (inputn[x][y] != inputN[x + i][y + j]) {
						flag = 0;
					}
				}
			}
			if (flag) {
				one++;
			}
			flag = 1;
			for (int x = 0;x < n;x++) {
				for (int y = 0;y < n;y++) {
					if (rotated90[x][y] != inputN[x + i][y + j]) {
						flag = 0;
					}
				}
			}
			if (flag) {
				two++;
			}

			flag = 1;
			for (int x = 0;x < n;x++) {
				for (int y = 0;y < n;y++) {
					if (rotated180[x][y] != inputN[x + i][y + j]) {
						flag = 0;
					}
				}
			}
			if (flag) {
				three++;
			}

			flag = 1;
			for (int x = 0;x < n;x++) {
				for (int y = 0;y < n;y++) {
					if (rotated270[x][y] != inputN[x + i][y + j]) {
						flag = 0;
					}
				}
			}
			if (flag) {
				four++;
			}
		}
	}
}

int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(cin >> N >> n){
		if (N == 0 && n == 0)
			break;
		initData();
		char c;
		cin.get(c);

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				cin.get(c);
				inputN[i][j] = c;
			}
			cin.get(c);
		}

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				cin.get(c);
				inputn[i][j] = c;
			}
			cin.get(c);
		}
		
		rotateMatrix();
		cal();

		cout << one << " " << two << " " << three << " " << four << endl;
	}

	//cout << mirror << endl;
	return 0;
}


/*
sample input
4 2
ABBA
ABBB
BAAA
BABB
AB
BB
6 2
ABCDCD
BCDCBD
BACDDC
DCBDCA
DCBABD
ABCDBA
BC
CD
0 0

sample output
0 1 0 0
1 0 1 0

*/
