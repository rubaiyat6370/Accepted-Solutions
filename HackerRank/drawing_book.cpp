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
vector<long long> arr(5);
long long A[5] = { 0 };
long long mn, mx;


int solve(int n, int p) {
	int mn1 = 0, mn2 = 0;
	if (n % 2 == 0) {
		n++;
	}

	mn1 = (n - p) / 2;
	mn2 = p / 2;

	return mn1<mn2 ? mn1 : mn2;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int n;
	cin >> n;
	int p;
	cin >> p;
	int result = solve(n, p);
	cout << result << endl;
	return 0;
}
