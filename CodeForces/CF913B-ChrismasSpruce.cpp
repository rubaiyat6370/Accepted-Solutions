#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
//int nodes[1001];
int tree[1001][1001];
int visited[1001][1001];
int childs[1001];
int n;

void initData() {
	for (int i = 0;i < 1001;i++) {
		for (int j = 0;j < 1001;j++) {
			tree[i][j] = 0;
			visited[i][j] = 0;
		}
		//nodes[i] = 0;
		childs[i] = -1;
	}
}

int dfs(int y) {
	int flag = 1;
	for (int i = 1;i <= n;i++) {
		if (visited[y][i]==0 && tree[y][i] == 1) {
			flag = 0;
			visited[y][i] = 1;
			int value = dfs(i);
			if (value == 1) {
				if (childs[y] == -1) {
					childs[y] += 2;
				}
				else childs[y]++;
			}
			else {
				if (childs[y] == -1)
					childs[y] = 0;
				else childs[y]--;
			}
		}
	}

	if (flag == 1) {
		return 1;
	}
	else return 0;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	initData();
	cin >> n;

	int p;

	//nodes[1] = 0;

	for (int i = 2;i <= n;i++) {
		cin >> p;
		tree[p][i] = 1;
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (visited[i][j] == 0 && tree[i][j] == 1) {

				visited[i][j] == 1;
				int val = dfs(j);
				if (val == 1) {
					if (childs[i] == -1) {
						childs[i]+=2;
					}
					else childs[i]++;
				}
				else {
					if (childs[i] == -1)
						childs[i] = 0;
					//else childs[i]--;
				}
			}
		}
	}
	int flag = 1;
	int isAny = 0;

	for (int i = 1;i <= n;i++) {
		if (childs[i]!=-1) {
			isAny = 1;
			if(childs[i]<3)
				flag = 0;
		}

	}

	if (isAny && flag) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;

	return 0;
}
