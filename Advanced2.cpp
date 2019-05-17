#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;

int n, m, mat[55][55], que[1000], qu;
bool visited[55][55];

void initialize()
{
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			visited[i][j] = false;
		}
	}
	qu = 0;
}

bool isValid(int x, int y)
{
	return x >= 0 && x<n && y >= 0 && y<m && !visited[x][y] && mat[x][y]>0;
}

bool bfs(int cur, int lev)
{
	if (cur == qu) return false;

	int v = que[cur];
	int x, y;
	x = v / m;
	y = v%m;


	if (isValid(x, y - 1))
	{
		if (mat[x][y - 1] == 3) return true;
		que[qu++] = x*m + y - 1;
		visited[x][y - 1] = true;
	}
	if (isValid(x, y + 1))
	{
		if (mat[x][y + 1] == 3) return true;
		que[qu++] = x*m + y + 1;
		visited[x][y + 1] = true;
	}

	for (int level = 1; level <= lev; level++) {
		int nextPos[2][2] = {
			{ x - level, y },
			{ x + level, y }
		};
		for (int i = 0; i < 2; ++i)
		{
			int p = nextPos[i][0];
			int q = nextPos[i][1];
			if (!isValid(p, q)) continue;
			if (mat[p][q] == 3) return true;
			que[qu++] = p*m + q;
			visited[p][q] = true;
		}
	}

	bfs(cur + 1, lev);
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &n, &m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &mat[i][j]);
			}
		}

		for (int level = 1; level <= n; level++) {
			initialize();
			visited[n - 1][0] = true;
			que[qu++] = (n - 1)*m;
			if (bfs(0, level))
			{
				printf("%d\n", level);
				break;
			}
		}
	}


	return 0;
}

/*
input:
3
5 6 
1 1 1 0 1 3 
1 1 1 0 0 0

0 0 0 0 0 0

0 0 0 0 0 0

2 1 1 1 1 1

5 6
1 1 1 1 1 3

1 1 1 0 0 0

0 0 0 0 0 0

0 0 0 0 0 0

2 1 1 1 1 1

5 6

1 1 1 0 1 3
1 1 1 0 0 0
0 0 0 0 0 1

0 0 0 0 0 0

2 1 1 1 1 1


output:
4

3
2

*/
