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

long long  matrix[301][301];

long long d[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };


void matrixRotation(long long r, long long m, long long n) {
	
	long long m1 = m, n1 = n;
	long long  r1 = r;

	for (int i = 0;i < m/2+1;i++) {
		m1 = m - i;
		n1 = n - i;
        	long long div = 2 * (m1 + n1 - 2*(i+1));
        
		if(div>0){
           	       r1 = r % (div);
        	}
        
		for (long long rot = 0;rot < r1;rot++) {
			
			long long px = i;
			long long py = i;

			long long prev = matrix[i][i];

			for (long long j = 0;j < 4;j++) {

				while ((px + d[j][0]) < m1 && (px + d[j][0]) >= (0 + i) && (py + d[j][1]) < n1 && (py + d[j][1]) >= (0 + i)) {
					px = px + d[j][0];
					py = py + d[j][1];

					long long temp = matrix[px][py];
					matrix[px][py] = prev;
					prev = temp;
				}
			}
		}

	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	long long m;
	long long n;
	long long r;
	cin >> m >> n >> r;
	
	for (long long matrix_i = 0;matrix_i < m;matrix_i++) {
		for (long long matrix_j = 0;matrix_j < n;matrix_j++) {
			cin >> matrix[matrix_i][matrix_j];
		}
	}

	matrixRotation( r, m, n);

	for (long long matrix_i = 0;matrix_i < m;matrix_i++) {
		for (long long matrix_j = 0;matrix_j < n;matrix_j++) {
			cout << matrix[matrix_i][matrix_j] <<" ";
		}
		cout << endl;
	}
	return 0;
}
