#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int N;
int grid[27][27];
int used[27];
int variables[27];
char output[27];
char input[27];

void initData() {
	for (int i = 0;i < 27;i++) {
		for (int j = 0;j < 27;j++) {
			grid[i][j] = 0;
		}
		used[i] = 0;
		variables[i] = 0;
		output[i] = ' ';
	}
}

void readData() {

	gets_s(input); // use gets() before submission

	N = 0;
	for (int i = 0;i < input[i];i++)
	{
		if (input[i] != ' ') {
			variables[input[i] - 'A'] = 1;
			N++;
		}
	}
	gets_s(input); // use gets() before submission

	for (int i = 0;input[i];i++) {
		if (input[i] == ' ')
			i++;
		int index1 = input[i] - 'A';
		i++;
		if (input[i] == '<')
			i++;
		int index2 = input[i] - 'A';
		grid[index1][index2] = 1;
		
	}
	//cin.ignore();
}

void solveOrdering(int i) {
	if (i == N) {
		output[i] = '\0';
		for (int p = 0;p < N;p++)
		{
			if (p != 0)
				cout << " "; // always be careful about extra space/newline
			cout << output[p];
		}
		cout << endl;
		return;
	}

	for (int j = 0;j < 27;j++) {
		if (variables[j] && !used[j]) {
			for (int k = 0;k < 27;k++)
				if (grid[j][k] && used[k])
					return;
			output[i] = j + 'A';
			used[j] = 1;
			solveOrdering(i + 1);
			used[j] = 0;
			
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	int isfirst = 1;
	while (T--) {
		cin.ignore();
		if(isfirst)
			cin.ignore();
		initData();
		readData();
		if (isfirst)
			isfirst = 0; 
		else			// always be careful about extra space/newline
			cout << endl;
		solveOrdering(0);
		if (output[N] != '\0')
			cout << "NO" << endl;
	}
	
	return 0;
}