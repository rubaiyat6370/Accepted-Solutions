#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int N,M;
int grid[101][101];
int used[101][101];
string input;
int area;
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };

void initData() {
	input = "";
	for (int i = 0;i < 101;i++) {
		for (int j = 0;j < 101;j++) {
			grid[i][j] = 0;
		}
		
	}
}

void initUsed() {
	
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			used[i][j] = 0;
		}

	}
}

bool isValid(int x, int y) {
	if (x >= 0 && y >= 0 && x < N && y < M && !used[x][y] && grid[x][y])
		return true;
	return false;
}

void dfs(int x, int y) {
	used[x][y] = 1;
	area++;
	for (int i = 0;i < 8;i++) {
		int px = x + dx[i];
		int py = y + dy[i];

		if (isValid(px, py)) {
			dfs(px, py);
		}

	}
}

void readData() {
	M = N = 0;
	while (getline(cin, input)) {
		if (input.length() == 0)
			return;
		if (input[0] == 'L' || input[0] == 'W')
		{
			M = input.length();
			for (int i = 0;i < M;i++) {
				if (input[i] == 'W')
					grid[N][i] = 1;
			}
			N++;
		}
		else if (input[0] - '0' >= 0 && input[0] - '0' <= 99) {

			int i,x=0,y=0;
			for (i = 0;i < input.length();i++) {
				if (input[i] == ' ')
					break;
				x = x * 10 + input[i] - '0';
			}
			for (i = i+1;i < input.length();i++) {
				if (input[i] == ' ')
					break;
				y = y * 10 + input[i] - '0';
			}
			area = 0;
			initUsed();
			if (isValid(x - 1, y - 1))
			{
				dfs(x - 1, y - 1);
			}
			cout << area << endl;
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	int isfirst = 1;
	while (T--) {
		if (isfirst)
		{
			cin.ignore();
			cin.ignore();
		}

		initData();
		if (isfirst)
			isfirst = 0;
		else
			cout << endl;
		readData();
	}
	
	return 0;
}