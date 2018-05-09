#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;
// bigInteger calculation
string addition(string a, string b) {

	string ans="";
	int i,j,temp=0;

	i = a.length()-1;
	j = b.length()-1;

	while (i >= 0 || j>=0) {
		if (i>=0 && a[i])
			temp += a[i] - '0';
		if (j>=0 && b[j])
			temp += b[j] - '0';
		int t = (temp % 10);
		char c = t + '0';
		ans = ans + c;
		temp = temp / 10;
		i--;
		j--;
	}
	while (temp > 0) {
		int t = (temp % 10);
		char c = t + '0';
		ans = ans + c;
		temp = temp / 10;
	}
	string fnal = "";

	for (int i = ans.length() - 1;i >= 0;i--) {
		fnal = fnal + ans[i];
	}

	return fnal;
}

void subtraction(string a, string b) {

}

string multiplication(string a, string b) {
	string a1, b1="0";
	int i, j, temp = 0,zero=0;
	i = a.length() - 1;

	int m1, m2;
	while (i >= 0) {
		a1 = "";
		m1 = a[i]-'0';
		j = b.length() - 1;
		while (j >= 0) {
			m2 = b[j] - '0';
			temp = temp + m1*m2;
			int t = temp % 10;
			char c = t + '0';
			a1 = a1 + c;
			temp = temp / 10;
			j--;
		}
		while (temp > 0) {
			int t = (temp % 10);
			char c = t + '0';
			a1 = a1 + c;
			temp = temp / 10;
		}

		string fnal = "";
		// reverse string
		for (int i = a1.length() - 1;i >= 0;i--) {
			fnal = fnal + a1[i];
		}
		a1 = fnal;
		//add zero
		for (int p = 0;p < zero;p++)
			a1 = a1 + '0';
		b1 = addition(a1, b1);
		i--;
		zero++;
	}
	cout << b1 << endl;
	return b1;
}

void division(string a, string b) {

}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string a, b;
	cin >> a >> b;
	//addition(a, b);
	multiplication(a, b);
	
	return 0;
}