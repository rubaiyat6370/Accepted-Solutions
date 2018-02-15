#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int flippingMatrix(vector < vector<int> > matrix) {
	int size = matrix.size();
	int n = size / 2;

	int result = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			result += max(max(matrix[r][c], matrix[size - 1 - r][c]),
				max(matrix[r][size - 1 - c], matrix[size - 1 - r][size - 1 - c]));
		}
	}
	return result;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int q;
	cin >> q;
	for (int a0 = 0; a0 < q; a0++) {
		int n;
		cin >> n;
		vector< vector<int> > matrix(2 * n, vector<int>(2 * n));
		for (int matrix_i = 0;matrix_i < 2 * n;matrix_i++) {
			for (int matrix_j = 0;matrix_j < 2 * n;matrix_j++) {
				cin >> matrix[matrix_i][matrix_j];
			}
		}
		int result = flippingMatrix(matrix);
		cout << result << endl;
	}
	return 0;
}



