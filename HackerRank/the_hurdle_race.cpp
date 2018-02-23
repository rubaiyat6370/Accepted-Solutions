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


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	int k;
	cin >> n >> k;
	vector<int> height(n);
	int mx = k;
	for (int height_i = 0; height_i < n; height_i++) {
		cin >> height[height_i];
		if (height[height_i]>mx)
			mx = height[height_i];
	}
	int result = mx - k;
	cout << result << endl;
	return 0;
}
