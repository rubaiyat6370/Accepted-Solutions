#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#define S 1000000

int a,b;


using namespace std;

void initData() {

}


int main() {

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			break;
		long long Ans = 0;;

		double rootOfA = sqrt(a);
		int rootOfB = sqrt(b);
		if (int(rootOfA) < rootOfA)
			rootOfA = int(rootOfA) + 1;
		Ans = rootOfB - rootOfA + 1;

		cout << Ans << endl;

	}

	return 0;
}
