#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define SIZE_K 21;
using namespace std;

int input[8][8];
int visited[8][8];
int k;
int Ans;
int output[5];


void initData() {
	Ans = 0;
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			input[i][j] = 0;
			visited[i][j] = 0;
		}
		
	}
}

void printData(int sum) {
	int counter = 0;
	do {
		output[counter] = sum % 10;
		sum = sum / 10;
		counter++;
	} while (sum > 0);

	for (int i = 0;i < 5 - counter;i++)
		cout << " ";
	for (int i = counter-1;i >=0;i--)
		cout << output[i];
}

//check only backward direction because forward direction is not calculated yet and remains unvisited
int checkLeftDiagonal(int i, int j) {
	while (i >= 0 && j >= 0) {
		if (visited[i][j] == 1)
			return 0;
		i--;
		j--;
	}
	return 1;
}

int checkRightDiagonal(int i, int j) {
	while (i >= 0 && j < 8) {
		if (visited[i][j] == 1)
			return 0;
		i--;
		j++;
	}
	return 1;
}

int checkUp(int i, int j) {
	while (i >= 0) {
		if (visited[i][j] == 1)
			return 0;
		i--;
	}
	return 1;
}

void permutation(int i, int sum) {
	if (i == 8) {
		if (sum > Ans)
			Ans = sum;
		return;
	}

	for (int j = 0;j < 8;j++) {
		if (checkLeftDiagonal(i,j) && checkRightDiagonal(i,j) && checkUp(i,j)) {
			visited[i][j] = 1;
			permutation(i + 1, sum + input[i][j]);
			visited[i][j] = 0;
		}
	}
}

void readData() {
	
	for (int i = 0;i < 8;i++)
		for (int j = 0;j < 8;j++)
			cin >> input[i][j];
}



int main() {
	freopen("in.txt", "r", stdin);

	cin >> k;
	for (int i = 0;i < k;i++) {
		initData();
		readData();
		permutation(0, 0);
		//printData(Ans);
		printf("%5d\n", Ans);
		
	}
	
	return 0;
}
