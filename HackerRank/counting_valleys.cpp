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

int countingValleys(int n, string s) {
	int v = 0;
	int step = 0;
	for (int i = 0;i < n;i++) {
		
		if (step == 0 && s[i] == 'D') {
			step--;
			
			while (step != 0 && i<n) {
				i++;
				if (s[i] == 'D') {
					step--;
				}
				else if (s[i] == 'U') {
					step++;
				}
			}
			if (step == 0)
			{
				v++;
			}
		}
		else if (s[i] == 'D') {

			step--;
		}
		else if (s[i] == 'U') {
			step++;
		}
	}
	return v;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int result = countingValleys(n, s);
	cout << result << endl;
	return 0;
}
