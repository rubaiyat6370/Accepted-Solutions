#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>


#define S 2000000+10

//12032 - The Monkey and the Oiled Bamboo

int input[S];
int k,n;

using namespace std;

void initData() {
	k = 0;
	for (int i = 0;i < n;i++) {

		input[i] = 0;
	}
}


int main() {

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;
	int mx = 0,in;
	for (int i = 0;i < T;i++) {
		cin >> n;
		mx = 0;
		for (int j = 1;j <= n;j++) {
			cin >> input[j];
			if (input[j] - input[j-1] > mx)
				mx = input[j] - input[j-1];
		}
		int flag = 1;
		k = mx;
		for (int j = 1;j <= n;j++) {

			int diff = input[j] - input[j - 1];
			if (diff == mx) {
				mx--;
			}
			else if (diff > mx || mx <=0 ) {
				flag = 0;
			}
				
		}

		if (flag) {
			cout << "Case " << i+1 << ": "<< k << endl;
		}
		else
			cout << "Case " << i+1 << ": " << k + 1 << endl;
	}

	return 0;
}
