#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int runningTime(vector <int> arr) {
	int shifts = 0;
	for (int i = 1; i < arr.size(); i++) {
		int value = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > value) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = value;
		shifts += i - (j + 1);
	}
	return shifts;
}

int main() {

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
	}
	int result = runningTime(arr);
	cout << result << endl;
	return 0;
}



