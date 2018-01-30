#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define S 27

using namespace std;

double weight[S][S];
double input[S][S];
int vis[S];
int path[S];
double cost[S];
int n, m, index, T;
int first, last;

int queue[S*S];

void initData() {
	index = 0;
	for (int i = 0;i < S;i++) {
		for (int j = 0;j < S;j++) {
			input[i][j] = 0;
			weight[i][j] = 0;
		}
		path[i] = 0;
		vis[i] = 1;
	}
}
void initVis() {
	for (int i = 0;i < S;i++) {
		vis[i] = 1;
	}
}
void initQueue() {
	first = 0, last = -1;
	for (int i = 0;i < S*S;i++) {
		queue[i] = 0;
		
	}
}

void push(int x, double cost) {
	++last;
	queue[last] = x;
	
}

int pop() {
	return queue[first++];
}

void bfs() {
	
	while (first <= last) {
		int x = pop();
		int temp = 0;
		for (int i = 1;i <= m;i++) {
			if (input[x][i] != 0) {
				weight[x][i] = cost[x] * input[x][i];

				if (cost[i] != 0) {
					weight[x][i] = cost[i] + weight[x][i];
				}
				cost[i] = weight[x][i];
				if (vis[i]) {
					push(i, cost[i]);
					vis[i] = 0;
				}

			}
		}
	}

}

void findPath(int x) {
	vis[x] = 0;
	path[index++] = x;
	double mx = 0;
	int temp;
	for (int i = 1;i <= m;i++) {
		if (weight[x][i] > mx) {
			mx = weight[x][i];
			temp = i;
		}
	}
	if (mx > 0 && T>0) {
		T -= 10;
		findPath(temp);
	}
}
int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> m >> T >> n;
	int a,b;
	initData();
	initQueue();
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		cin >> input[a][b];
		//input[b][a] = input[a][b];
	}
	
	cost[1] = 1;
	push(1,1);
	bfs();

	weight[0][1] = 0;
	initVis();
	if (T - 10 >= 0) {
		T -= 10;
		findPath(1);
		if (T >= 10) {
			cout << "Impossible" << endl;
		}
		else {
			cout << "node: " << path[index-1] << " probability: " << cost[path[index - 1]] << endl;
		}
	}
	else {
		cout << "node: " << 1 << " probability: " << 1 << endl;
	}
	return 0;
}

/*
10 30
14
1 2 .2
1 3 .8
2 4 .4
2 5 .6
3 5 .3
3 6 .7
4 8 .6
4 7 .4
5 7 1
6 7 .5
6 9 .5
7 8 1
8 10 1
9 10 1

*/
