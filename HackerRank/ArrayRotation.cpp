#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
	vector<int> out(n);
	k = k%n;
	for (int i = 0;i<n;i++) {
		if ((i - k)>=0) {
			out[i - k] = a[i];
		}
		else {
			int left = k - (i);
			out[n - left] = a[i];
		}
	}
	return out;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	int k;
	cin >> n >> k;
	vector<int> a(n);
	for (int a_i = 0;a_i < n;a_i++) {
		cin >> a[a_i];
	}
	vector<int> output = array_left_rotation(a, n, k);
	for (int i = 0; i < n;i++)
		cout << output[i] << " ";
	cout << endl;
	return 0;
}
