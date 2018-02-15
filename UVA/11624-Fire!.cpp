#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define S 1001

using namespace std;

struct point {
	int x;
	int y;
	int dis;
};

char input[S][S];
int fireVisited[S][S];
int joeVisited[S][S];
int R, C;
int minimum;
point queue[1000002];
int first, last;

void initData() {
	minimum = 999999999;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			input[i][j] = ' ';
			fireVisited[i][j] = 0;
			joeVisited[i][j] = 0;
		}
	}
}

void initArr() {
	first = 0, last = -1;
	for (int i = 0;i < R*C;i++) {
		queue[i].x = 0;
		queue[i].y = 0;
		queue[i].dis = 0;
	}
}

void push(int x,int y,int dis) {
	++last;
	queue[last].x = x;
	queue[last].y = y;
	queue[last].dis = dis;
}

point pop() {
	return queue[first++];
}

void joe(int i, int j, int dis) {
	push(i, j, dis);
	joeVisited[i][j] = 1;

	while (first <= last) {
		point p = pop();
		dis = p.dis + 1;
		if ((p.x == R - 1 && p.y <= C) || (p.x <= R && p.y == C - 1) || (p.x==0 && p.y>=0) || (p.x>=0 && p.y==0)) {
			if (dis <= minimum) {
				minimum = dis;
			}
			break;
		}

		if (input[p.x][p.y + 1] == '.' && (fireVisited[p.x][p.y + 1] > dis || fireVisited[p.x][p.y + 1]==0) && joeVisited[p.x][p.y + 1]==0) {
			push(p.x, p.y + 1, dis);
			joeVisited[p.x][p.y + 1] = dis;
			
		}

		if (input[p.x][p.y - 1] == '.' && joeVisited[p.x][p.y - 1] == 0 && (fireVisited[p.x][p.y - 1]>dis || fireVisited[p.x][p.y - 1]==0)) {
			push(p.x, p.y - 1, dis);
			joeVisited[p.x][p.y - 1] = dis;
			
		}

		if (input[p.x + 1][p.y] == '.' && joeVisited[p.x + 1][p.y] == 0 && (fireVisited[p.x + 1][p.y] > dis || fireVisited[p.x + 1][p.y]==0)) {
			push(p.x + 1, p.y, dis);
			joeVisited[p.x + 1][p.y] = dis;
			
		}
		if (input[p.x - 1][p.y] == '.' && joeVisited[p.x - 1][p.y] == 0 && (fireVisited[p.x - 1][p.y] > dis || fireVisited[p.x - 1][p.y]==0)) {
			push(p.x - 1, p.y, dis);
			joeVisited[p.x - 1][p.y] = dis;
		}

	}
}

void fire() {
	int dis;
	while (first <= last) {
		point p = pop();
		dis = p.dis+1;
		if ((input[p.x][p.y + 1] == '.' || input[p.x][p.y + 1] == 'J')  && fireVisited[p.x][p.y + 1]==0) {
			push(p.x, p.y + 1,dis);
			fireVisited[p.x][p.y + 1] = dis;
		}
		if ((input[p.x][p.y - 1] == '.' || input[p.x][p.y - 1] == 'J') && fireVisited[p.x][p.y - 1] == 0) {
			push(p.x, p.y - 1,dis);
			fireVisited[p.x][p.y - 1] = dis;
		}
		if ((input[p.x + 1][p.y] == '.' || input[p.x + 1][p.y] =='J') && fireVisited[p.x + 1][p.y] == 0) {
			push(p.x + 1, p.y,dis);
			fireVisited[p.x + 1][p.y] = dis;
		}
		if ((input[p.x - 1][p.y] == '.' || input[p.x - 1][p.y] == 'J' )&& fireVisited[p.x - 1][p.y] == 0) {
			push(p.x - 1, p.y,dis);
			fireVisited[p.x - 1][p.y] = dis;
		}
	}
}

int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w", stdout);

	int T, jx,jy,fx,fy;
	jx = jy = fx = fy = -1;
	cin >> T;

	for (int i = 1;i <= T;i++) {

		cin >> R >> C;
		initData();
		initArr();
		char c;
		for (int j = 0;j < R;j++) {
			for (int k = 0;k < C;k++) {
				cin >> c;
				if (c == '#') {
					input[j][k] = c;
					fireVisited[j][k] = -1;
					joeVisited[j][k] = -1;
				}
				else if (c == '.') {
					input[j][k] = c;
				}
				else if (c == 'J'){
					input[j][k] = c;
					jx = j;
					jy = k;
				}
				else if (c == 'F') {
					input[j][k] = c;
					fx = j;
					fy = k;
					push(fx, fy,0);
					fireVisited[j][k] = 1;
				}
				
			}
		}

		if (fx != -1) {
			fire();
			initArr();
			joe(jx, jy, 0);
		}
		else {
			joe(jx, jy, 0);
		}

		if (minimum < 999999999) {
			cout << minimum << endl;
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
