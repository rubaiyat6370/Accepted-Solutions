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


long strangeCode(long t) {
	long counter = 3;
	long icounter = 3;
	long c = 1;
	while (c+counter <=t) {
		c = c + counter;
		counter = counter * 2;
	}
	if (c != t) {
		c = t - c;
		counter = counter - c;
	}

	return counter;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	long t;
	cin >> t;
	long result = strangeCode(t);
	cout << result << endl;
	return 0;
}

/*
while (c<=t) {

if (c == t) {
break;
}
if (counter == 1)
{
counter = icounter * 2;
icounter = counter;
c++;
if (c == t) {
return counter;
}
}

c= c+ (counter-1);
counter=1;

}
*/