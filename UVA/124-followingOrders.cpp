#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stdio.h>



#define size_n 1001
using namespace std;

int N;
int task[28][28];
int dependency[28];
int used[28];
int variables[28];
char output[28];
char line[1212];

void initData() {
	for (int i = 0;i < 28;i++) {
		for (int j = 0;j < 28;j++) {
			task[i][j] = 0;
		}
		variables[i] = 0;
		//dependency[i] = 0;
		used[i] = 0;
		output[i] = ' ';
	}
}


void readData() {
	N = 0;
	for (int i = 0;line[i];i++)
		if (line[i] != ' ')
		{
			variables[line[i] - 'a'] = 1;
			N++;
		}
	gets_s(line); // before submission make it gets

	for (int i = 0;line[i];i++) {
		if (line[i] == ' ')
			i++;
		int index1 = line[i] - 'a';
		i++;

		if (line[i] == ' ')
			i++;

		int index2 = line[i] - 'a';

		task[index1][index2] = 1;
		//dependency[index2]++;
	}

}

void solve(int i) {
	if (i == N) {
		output[i] = '\0';
		printf("%s\n", output);
		return;
	}

	for (int j = 0;j < 27;j++) {
		if (variables[j] && !used[j]) {

			for (int k = 0;k < 27;k++) {
				if (task[j][k] && used[k]) {
					return;
				}
				//else if (task[j][k] && !used[k] && dependency[k] > 0)
					//dependency[k]--;
				
			}
			used[j] = 1;
			output[i] = j + 'a';
			solve(i + 1);
			used[j] = 0;
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int isFirst = 1;
	while (gets_s(line)) { // before submission make it gets
		initData();
		readData();
		if (isFirst)
			isFirst = 0;
		else
		{
			cout << endl;
		}
		solve(0);
		
		
	}
	return 0;
}