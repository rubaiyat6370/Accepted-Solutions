#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
int n, m;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> n >> m;

	if (n >= 27 || n > m) {
		cout << m << endl;
	}
	else {
		long long s = 1;
		for (int i = 0;i<n;i++) {
			s = s * 2;
		}
		long long r = m % s;

		cout << r << endl;
	}

	return 0;
}
