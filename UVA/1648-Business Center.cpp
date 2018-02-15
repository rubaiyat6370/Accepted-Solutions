#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define S 27

using namespace std;
//1648	Business Center
int n, m;
int u, d;
long long mn = 999999999999;

void initData() {
	
	mn = 999999999999;
}
//TLE
void calMin() {
	long long up = 0, down = 0;
	long long low = 0, high = n;
	for (int i = 0;i <= n;i++) {
		up = i*u;
		down = (n - i)*d;
		
		if ((up - down) > 0 && (up - down) < mn) {
			mn = up - down;
			break;
		}
	}
}
//Accepted
void findFloor() {
	long long f;
	long long low = 0,high = n,mid;

	while (low<=high) {

		mid = (high + low) / 2;

		f = mid*u - (n - mid)*d;

		if (f < mn && f>0) {
			mn = f;
		}
		if (f < 1)
		{
			low = mid+1;
		}
		else {
			high = mid-1;
		}
		
	}
}

int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> n >> m) {
		initData();
		for (int i = 0;i < m;i++) {
			cin >> u >> d;
			//calMin();
			findFloor();
		}

		cout << mn << endl;
	}
}

/*
10 3
15 12
15 4
7 12

*/
