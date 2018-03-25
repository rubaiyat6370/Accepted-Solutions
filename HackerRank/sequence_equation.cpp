#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

void permutationEquation(vector <int> p, int n) {
	for (int i = 1;i<n+1;i++) {
		for (int j = 1;j<=p.size();j++) {
			if (p[p[j]] && (p[p[j]] == i))
			{
				cout << j << endl;
				break;
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> p(n+1);
	for (int p_i = 1; p_i <= n; p_i++) {
		cin >> p[p_i];
	}
	permutationEquation(p,n);

	return 0;
}