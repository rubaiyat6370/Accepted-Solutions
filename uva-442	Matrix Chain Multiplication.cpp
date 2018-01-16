#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

char mat[27];
int row[27];
int col[27];


int n1, m1, n2, m2;

int n;

struct node {
	int row;
	int col;
};

node input[27] ;

void initData() {
	for (int i = 0;i < 27;i++) {
		mat[i] = ' ';
		row[i] = 0;
		col[i] = 0;
	}
}


int main() {

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	initData();

	cin >> n;

	n1 = m1 = n2 = m2 = 0;
	for (int i = 0;i < n;i++) {
		cin >> mat[i] >> row[i] >> col[i];
	}

	char c;
	cin.get(c);
	while (cin.get(c)) {
		int top = 0;
		int total = 0;
		int par = 0;
		int flag = 1;

		if (c >= 65 && c <= 90) {
			cout << total << endl;
			cin.get(c);
		}
		else {

			while (c!='\n' && c!='\r') {
				
				if (c == '(') {
					par++;
				}
				
				else if (c == ')') {
					par--;
					node num2 = input[top - 1];

					top--;
					node num1 = input[top - 1];
					top--;

					n1 = num1.row;
					m1 = num1.col;

					n2 = num2.row;
					m2 = num2.col;

					if (m1 != n2) {
						flag = 0;
					}
					else {
						total = total + (n1*m1*m2);
						node temp;
						temp.row = n1;
						temp.col = m2;
						input[top++] = temp;
					}
				}
				else if (c >= 65 && c <= 90) {
					node temp ;
					temp.row = row[c - 65];
					temp.col = col[c - 65];
					input[top++] = temp;
				}
				cin.get(c);
			}

			if (c == '\n' || c== '\r')
			{
				if (flag) {
					cout << total << endl;
				}
				else {
					cout << "error" << endl;
				}
				par = 0;
			}
		}
	}

	return 0;
}
