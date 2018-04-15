#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;
int N, E;
int graph[205][205];
int visited[205][205];
int color[205];
bool isBicolorable;
	
void initialize() {
	isBicolorable = true;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			graph[i][j] = 0;
			visited[i][j] = 0;
		}
		color[i] = 0;
	}
}

void checkColor(int i, int clr) {

	for (int j = 0;j < N;j++) {
		if (i != j && color[j] && color[i] && color[j] == color[i] && graph[i][j]==1) {
			isBicolorable = false;
		}
		else if (graph[i][j] == 1 && visited[i][j] == 0 ) {
			graph[i][j] = 0;
			graph[j][i] = 0;
			visited[i][j] = 1;
			if(clr==1)
				color[j] = 2;
			if (clr == 2)
				color[j] = 1;
			checkColor(j, color[j]);
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int c = 0;
	while (cin >> N && N != 0) {
		c++;
		initialize();
		cin >> E;
		int a, b;
		for (int i = 0;i < E;i++) {
			cin >> a >> b;
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		for (int i = 0;i <N;i++) {
			for (int j = 0;j <N;j++) {
				if (graph[i][j] == 1 && visited[i][j]==0) {
					color[i] = 1; 
					checkColor(i, 1);
				}
			}
			
		}

		if (isBicolorable) {
			cout << "BICOLORABLE." << endl;
		}
		else {
			cout << "NOT BICOLORABLE." << endl;
		}

	}

	
	return 0;
}

/*
sample input:
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0

sample output:

NOT BICOLORABLE.
BICOLORABLE.
BICOLORABLE.
*/