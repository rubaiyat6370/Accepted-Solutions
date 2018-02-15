#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
long long MAX = 9876543210;

bool check(long long n) {
	int arr[10];
	for (int i = 0;i < 10;i++) {
		arr[i] = 0;
	}
	int v = 0;
	do {
		v = n % 10;
		n = n / 10;
		arr[v]++;
	} while (arr[v] == 1 && n>0);

	for (int i = 0;i < 10;i++) {
		if (arr[i] > 1)
			return false;
	}
	return true;
}

int main() {
	freopen("inputHack.txt", "r", stdin);
	freopen("outHack.txt", "w", stdout);

	int T = 0;
	cin >> T;
	for (int i = 0;i < T;i++)
	{
		char hudai;
		cin.get(hudai);
		long long number;
		long long N;
		long long j = 1;
		cin >> N;

		if(i!=0) cout << "\n";

		do {
			number = N*j;

			if (check(number) && check(j)) {
				cout << number << " / " << j << " = " << N << endl;
			}
			j++;
		} while (number <= MAX);

		
	}
}
