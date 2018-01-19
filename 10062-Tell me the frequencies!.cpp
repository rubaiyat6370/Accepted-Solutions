#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#define S 2000+10

//10062-Tell me the frequencies 

using namespace std;

string input;
int ascii[S];

void initData() {
	for (int i = 32;i <= 128;i++) {
		ascii[i] = 0;
	}
}


int main() {
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int flag = 0;
	int mx;
	char c;
	while(cin.get(c)){
		initData();
		mx = 0;
		while (c!= '\n' && c!='\r') {
			if (c <= 32 || c <= 128) {
				ascii[c]++;
			}

			if (ascii[c] > mx)
				mx = ascii[c];
			cin.get(c);
		}

		if (flag == 0) {
			flag = 1;
		}
		else
			cout << endl;

		for (int x = 1;x <=mx;x++) {
			for (int i = 128;i >= 32;i--) {
				if (ascii[i] == x) {
					cout << i << " " << ascii[i] << endl;
				}
			}
		}
		
	}
	return 0;
}


/*
sample input
AAABBC
122333

sample output
67 1
66 2
65 3


*/
