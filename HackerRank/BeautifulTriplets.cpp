#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int dip[20000 + 10];
int in[10010];

int main(){
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n, d;
	cin >> n >> d;
	int k;
	int j = 0;
	for (int i = 0; i < n; i++){
		cin >> k;
		if (dip[k] == 0){
			in[j] = k;
			j++;
		}
		dip[k]++;
		
	}

	int triplets = 0;
	for (int i = 0; i < j; i++){
		int tar = in[i];

		if (dip[tar + d] && dip[tar + 2 * d]){
			triplets = triplets + dip[tar] * dip[tar + d] * dip[tar + 2 * d];
		}
	}
	
	cout << triplets << endl;
	return 0;
}
