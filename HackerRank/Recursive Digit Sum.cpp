#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int digitSum(string n, int k) {
	long long sum = 0;
	for (int i = 0;i < n.length();i++) {
		sum += n[i]-'0';
	}
	sum *= k;
	long long temp = sum;
	sum = 0;
	do {
		sum += temp % 10;
		temp = temp / 10;

		if (temp == 0) {
			if (sum > 9) {
				temp = sum;
				sum = 0;
			}
		}
	} while (temp > 0);

	return sum;
}
int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string n;
	int k;
	cin >> n >> k;
	int result = digitSum(n, k);
	cout << result << endl;
	return 0;
}



