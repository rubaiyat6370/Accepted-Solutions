#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

using namespace std;

int jumpingOnClouds(vector <int> c, int k) {
	int E = 100;
	int n = c.size();
	k = k%n;
	int step = k;

	while (step != 0) {
		E = E - 1;
		if (c[step])
			E = E - 2;
		step = (step + k) % n;
	}

	E = E - 1;
	if (c[step])
		E = E - 2;

	return E;
}

int main() {
	int n;
	int k;
	cin >> n >> k;
	vector<int> c(n);
	for (int c_i = 0; c_i < n; c_i++) {
		cin >> c[c_i];
	}
	int result = jumpingOnClouds(c, k);
	cout << result << endl;
	return 0;
}