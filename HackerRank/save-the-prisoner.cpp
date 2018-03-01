#include <bits/stdc++.h>

using namespace std;

long long saveThePrisoner(long long n, long long m, long long s) {
	
	long long sum = n;
	
	int i = 1;
	if (m >= n && n) {
		m = m - (n - s + 1);
		m = m%n;
		if (m == 0)
			return n;
		return m;
	}
	else {
		sum = s+m-1;
		if (sum <= n)
			return sum;
		else {
			m = m - (n-s+1);
			return 1 + m - 1;
		}
	}
    
    /*
    m = (s+m-1)%n;
    if(m==0) return n;
    else return m;
    */
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        int s;
        cin >> n >> m >> s;
        long long result = saveThePrisoner(n, m, s);
        cout << result << endl;
    }
    return 0;
}
