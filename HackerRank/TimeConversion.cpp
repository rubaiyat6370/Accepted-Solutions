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


string timeConversion(string s) {
	string str2 = s.substr(0, 2);

	if (s[8] == 'P') {
		int h = stoi(str2);
		h = h + 12;
		if (h == 24) {
			return "12"+ s.substr(2, 6);
		}
		return to_string(h) + s.substr(2, 6);
	}
	if (s[8] == 'A' && str2=="12") {
		str2 = "00";
		return str2 + s.substr(2, 6);
	}
	
	else 
		return s.substr(0,8);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	
	string s;
	cin >> s;
	string result = timeConversion(s);
	cout << result << endl;
	return 0;
}
