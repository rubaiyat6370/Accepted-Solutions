#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	int k;
	int q;
	cin >> n >> k >> q;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	vector<int> m(q);
	for (int m_i = 0; m_i < q; m_i++) {
		cin >> m[m_i];
	}
	for (int i = 0;i < q;i++) {
		cout << a[(n + m[i] - (k%n))%n] << endl;
	}
	// if after rotation position is x, total element n and number of shift k 
	// then initial position = (n + x - (k%n))%n ;
	
	// after rotation position = (initial position+k)%n ; 

	return 0;
}