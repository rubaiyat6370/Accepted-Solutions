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

int magicSquare1[3][3] = { { 4,9,2 },
						   { 3,5,7 },
						   { 8,1,6 } };

int magicSquare7[3][3] = { { 8,1,6 },
						   { 3,5,7 },
                           { 4,9,2 } };

int magicSquare5[3][3] = { { 2,9,4 },
                           { 7,5,3 },
                           { 6,1,8 } };

int magicSquare2[3][3] = { { 8,3,4 },
						   { 1,5,9 },
						   { 6,7,2 } };

int magicSquare6[3][3] = { { 4,3,8 },
						   { 9,5,1 }, 
						   { 2,7,6 } };
int magicSquare8[3][3] = { { 6,7,2 },
                           { 1,5,9 },
                           { 8,3,4 } };
						   

int magicSquare3[3][3] = { { 6,1,8 },
						   { 7,5,3 },
						   { 2,9,4 } };

int magicSquare4[3][3] = { { 2,7,6 },
						   { 9,5,1 },
						   { 4,3,8 } };





int formingMagicSquare(vector < vector<int> > s) {
	int mn = 999999;
	int cost = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if(s[i][j]!=magicSquare1[i][j]){
				cost = cost + abs(s[i][j] - magicSquare1[i][j]);
			}
		}
	}
	if (cost < mn)
		mn = cost;
	cost = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (s[i][j] != magicSquare2[i][j]) {
				cost = cost + abs(s[i][j] - magicSquare2[i][j]);
			}
		}
	}
	if (cost < mn)
		mn = cost;

	cost = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (s[i][j] != magicSquare3[i][j]) {
				cost = cost + abs(s[i][j] - magicSquare3[i][j]);
			}
		}
	}
	if (cost < mn)
		mn = cost;

	cost = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (s[i][j] != magicSquare4[i][j]) {
				cost = cost + abs(s[i][j] - magicSquare4[i][j]);
			}
		}
	}
	if (cost < mn)
		mn = cost;

	cost = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (s[i][j] != magicSquare5[i][j]) {
				cost = cost + abs(s[i][j] - magicSquare5[i][j]);
			}
		}
	}
	if (cost < mn)
		mn = cost;

	cost = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (s[i][j] != magicSquare6[i][j]) {
				cost = cost + abs(s[i][j] - magicSquare6[i][j]);
			}
		}
	}
	if (cost < mn)
		mn = cost;

	cost = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (s[i][j] != magicSquare7[i][j]) {
				cost = cost + abs(s[i][j] - magicSquare7[i][j]);
			}
		}
	}
	if (cost < mn)
		mn = cost;

	cost = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (s[i][j] != magicSquare8[i][j]) {
				cost = cost + abs(s[i][j] - magicSquare8[i][j]);
			}
		}
	}
	if (cost < mn)
		mn = cost;

	return mn;
}


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	vector< vector<int> > s(3, vector<int>(3));
	for (int s_i = 0;s_i < 3;s_i++) {
		for (int s_j = 0;s_j < 3;s_j++) {
			cin >> s[s_i][s_j];
		}
	}
	int result = formingMagicSquare(s);
	cout << result << endl;
	return 0;
}
