#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
int isSeperable;
int input[21];
char in[1001];
int N, total;
void initialize() {
	total = 0;
	isSeperable = 0;
	for (int i = 0;i < 21;i++) {
		input[i] = 0;
	}
}

void readData() {
	int c=0;
	//cin.ignore();
	gets_s(in); // make it gets before submission

	for (int i = 0;in[i];i++) {
		if (in[i] == ' ')
			i++;
		
		int x=0;
		while (in[i] && in[i] != ' ') {
			x = x * 10 + in[i++]-'0';
		}
		total += x;
		input[c++] = x;
		if (!in[i])
			break;
	}

	N = c;
}

void solve(int i, int sum, int half) {
	//if (sum == half) {
		//isSeperable = 1;
		//return;
	//}
	if (i == N) {
		int s1 = total - sum;
		if (s1 == sum) {
			isSeperable = 1;
		}
		return;
	}

	solve(i + 1, sum,half);
	solve(i + 1, sum + input[i], half);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;
	int isFirst = 1;
	while (T--) {
		initialize();
		if (isFirst) {
			isFirst = 0;
			cin.ignore();
		}
	
		readData();
		//if (total % 2 == 0) {
			solve(0, 0, total/2);
		//}

		if (isSeperable) {
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}

/*
input:
3
1 2 1 2 1
2 3 4 1 2 5 10 50 3 50
3 5 2 7 1 7 5 2 8 9 1 25 15 8 3 1 38 45 8 1

output:
NO
YES
YES

*/