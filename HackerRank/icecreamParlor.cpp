#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

void icecreamParlor(int m, vector <int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] + arr[j] == m) {
				cout << i + 1 << " " << j + 1 << endl;
				return;
			}
		}
	}
}

int main() {
	
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int m;
		cin >> m;
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int arr_i = 0; arr_i < n; arr_i++) {
			cin >> arr[arr_i];
		}
		icecreamParlor(m, arr);

	}
	return 0;
}
