#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#define NULLPTR NULL
#define SIZE_NUMBER 10
#define SIZE 100005

using namespace std;

int reminder[100000];

void INIT(){
	for (int i = 0; i < SIZE; i++)
		reminder[i] = 0;
}

int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	INIT();

	int k, n;
	cin >> n >> k;
	int num;
	int result = 0;
	while (n--){
		cin >> num;
		reminder[num%k]++;
	}

	if (reminder[0]>0)
		result++;
	for (int i = 1; i <= (k / 2); i++){
		if (i == (k - i))
			result++;
		else if (reminder[i] > reminder[k - i])
			result = result + reminder[i];
		else
			result = result + reminder[k - i];
	}

	cout << result << endl;

	return 0;
}
