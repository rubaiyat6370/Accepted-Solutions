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

vector <int> cutTheSticks(vector <int> arr, int mn) {
	int s = arr.size();
	int newmn;
	vector<int> result;
	while (s>0) {
		result.push_back(s);
		vector<int> a;
		newmn = 1001;
		for (int i = 0;i<s;i++) {
			int diff = (arr[i] - mn);
			if (diff>0) {
				a.push_back(diff);
				if (diff<newmn)
					newmn = diff;
			}
		}
		s = a.size();
		arr = a;
		mn = newmn;
	}
	return result;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> arr(n);
	int mn = 1001;
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
		if (arr[arr_i]<mn)
			mn = arr[arr_i];
	}
	vector <int> result = cutTheSticks(arr, mn);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << (i != result.size() - 1 ? "\n" : "");
	}
	cout << endl;


	return 0;
}
