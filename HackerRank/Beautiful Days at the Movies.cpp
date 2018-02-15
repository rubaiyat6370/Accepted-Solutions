#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>

using namespace std;

string reverse(string s) {
	for (long long i = 0; i < s.length() / 2; ++i)
		swap(s[i], s[s.length() - i - 1]);
	return s;
}
int main()
{
	
	long long i, j, k;
	cin >> i >> j >> k;
	string s = "";
	int counter = 0;
	for (long long m = i;m <= j;m++) {
		s = to_string(m);
		s = reverse(s);
		stringstream ss(s);
		long long x = 0;
		ss >> x;

		if (abs(m-x)%k == 0) {
			counter++;
		}
	}
	cout << counter << endl;
	

	return 0;
}