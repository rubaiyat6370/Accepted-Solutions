#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char c;
	int bracket = 0;
	while (c = getchar()) {
		if (c == EOF) {
			break;
		}
		if (c == '\"'){
			if (bracket == 0){
				cout << "\`\`";
				bracket++;
			}
			else if (bracket == 1){
				cout << "\'\'";
				bracket--;
			}
		}
		else {
			cout << c;
		}
	}
	return 0;
}
