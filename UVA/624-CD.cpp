#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;
int capacity, N;
int duration[21];
int bin[21];
int Ans;
int A[21];

void initialize()
{
	Ans = 0;
	for (int i = 0;i < 21;i++)
	{
		duration[i] = 0;
		bin[i] = 0;
		A[i] = 0;
	}
}

void solve(int i, int cap, int sum) {
	if (i == N) {
		if (sum > Ans)
		{
			Ans = sum;
			for (i = 0;i < N;i++) {
				A[i] = bin[i];
			}
		}
		return;
	}
	bin[i] = 0;
	solve(i + 1, cap, sum);

	if (cap - duration[i] >= 0) {
		bin[i] = duration[i];
		solve(i + 1, cap - duration[i], sum + duration[i]);
	}
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> capacity) {
		initialize();
		cin >> N;
		for (int i = 0;i < N;i++)
			cin >> duration[i];
		solve(0, capacity, 0);
		for (int i = 0;i < N;i++) {
			if (A[i]) {
				cout << A[i] << " ";
			}
		}
		cout << "sum:" << Ans << endl;
	}
	

	return 0;
}

/*
input:
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2
45 8 4 10 44 43 12 9 8 2

output:
1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
43 2 sum:45
43 2 sum:45

*/