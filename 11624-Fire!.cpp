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
int check[S][S];
int checkJ[S][S];
int R, C;
int minimum;
point arr[1000002];
int first, last;

void initData() {
	minimum = 999999999;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			input[i][j] = ' ';
			check[i][j] = 0;
			checkJ[i][j] = 0;
		}
	}
}

void initArr() {
	first = 0, last = -1;
	for (int i = 0;i < R*C;i++) {
		arr[i].x = 0;
		arr[i].y = 0;
		arr[i].dis = 0;
	}
}

void push(int x,int y,int dis) {
	++last;
	arr[last].x = x;
	arr[last].y = y;
	arr[last].dis = dis;
}

point pop() {
	return arr[first++];
}

void joe(int i, int j, int dis) {
	push(i, j, dis);
	checkJ[i][j] = 1;

	while (first <= last) {
		point p = pop();
		dis = p.dis + 1;
		if ((p.x == R - 1 && p.y <= C) || (p.x <= R && p.y == C - 1) || (p.x==0 && p.y>=0) || (p.x>=0 && p.y==0)) {
			if (dis <= minimum) {
				minimum = dis;
			}
			break;
		}

		if (input[p.x][p.y + 1] == '.' && (check[p.x][p.y + 1] > dis || check[p.x][p.y + 1]==0) && checkJ[p.x][p.y + 1]==0) {
			push(p.x, p.y + 1, dis);
			checkJ[p.x][p.y + 1] = dis;
			
		}

		if (input[p.x][p.y - 1] == '.' && checkJ[p.x][p.y - 1] == 0 && (check[p.x][p.y - 1]>dis || check[p.x][p.y - 1]==0)) {
			push(p.x, p.y - 1, dis);
			checkJ[p.x][p.y - 1] = dis;
			
		}

		if (input[p.x + 1][p.y] == '.' && checkJ[p.x + 1][p.y] == 0 && (check[p.x + 1][p.y] > dis || check[p.x + 1][p.y]==0)) {
			push(p.x + 1, p.y, dis);
			checkJ[p.x + 1][p.y] = dis;
			
		}
		if (input[p.x - 1][p.y] == '.' && checkJ[p.x - 1][p.y] == 0 && (check[p.x - 1][p.y] > dis || check[p.x - 1][p.y]==0)) {
			push(p.x - 1, p.y, dis);
			checkJ[p.x - 1][p.y] = dis;
		}

	}
}

void fire() {
	int dis;
	while (first <= last) {
		point p = pop();
		dis = p.dis+1;
		if ((input[p.x][p.y + 1] == '.' || input[p.x][p.y + 1] == 'J')  && check[p.x][p.y + 1]==0) {
			push(p.x, p.y + 1,dis);
			check[p.x][p.y + 1] = dis;
		}
		if ((input[p.x][p.y - 1] == '.' || input[p.x][p.y - 1] == 'J') && check[p.x][p.y - 1] == 0) {
			push(p.x, p.y - 1,dis);
			check[p.x][p.y - 1] = dis;
		}
		if ((input[p.x + 1][p.y] == '.' || input[p.x + 1][p.y] =='J') && check[p.x + 1][p.y] == 0) {
			push(p.x + 1, p.y,dis);
			check[p.x + 1][p.y] = dis;
		}
		if ((input[p.x - 1][p.y] == '.' || input[p.x - 1][p.y] == 'J' )&& check[p.x - 1][p.y] == 0) {
			push(p.x - 1, p.y,dis);
			check[p.x - 1][p.y] = dis;
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
					check[j][k] = -1;
					checkJ[j][k] = -1;
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
					check[j][k] = 1;
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
