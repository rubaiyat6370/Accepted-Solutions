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
int dp[101] = { 0 };

int pickingNumbers(vector <int> a, int n) {
	int mx = 0;
	for (int i = 0;i<n - 1;i++) {
		int s = dp[i] + dp[i + 1];
		if (s>mx)
			mx = s;
	}
	return mx;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
		dp[a[a_i]]++;
	}
	int result = pickingNumbers(a, n);
	cout << result << endl;
	return 0;
}
