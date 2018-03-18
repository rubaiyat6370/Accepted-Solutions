#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int N, r;
int binary[100];

void initialize()
{
	
	for (int i = 0;i < 100;i++)
	{
		binary[i] = 0;
	}
	
}

void print() {
	for (int i = 0;i < N;i++) {
		cout << binary[i];
	}
	cout << endl;
}
void solve(int i, int count) {
	if (i == N) {
		if (count == r) {
			print();
		}
		return;
	}
	binary[i] = 0;
	solve(i + 1, count);

	
		binary[i] = 1;
		solve(i + 1, count + 1);
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int T, isfirst = 1;
	cin >> T;
	while (T--) {
		cin.ignore();
		cin.ignore();

		if (isfirst)
			isfirst = 0;
		else
			cout << endl;

		cin >> N >> r;
		solve(0, 0);

	}
	return 0;
}

/*
input:
1

4 2

4 2

output:

0011
0101
0110
1001
1010
1100

0011
0101
0110
1001
1010
1100
*/