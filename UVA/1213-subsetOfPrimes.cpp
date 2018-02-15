#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE_k 15 
#define SIZE_N 189

using namespace std;

int n, k;
int subsetCount;
int binary[SIZE_N];
int flag[SIZE_N];
int subset[SIZE_N];

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401,
409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523,
541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653,
659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063,
1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117 };

int update(int size)
{
	int countSet = 0;
	for (int j = 0; j < size; j++)
	{
		if (binary[j] == 1)
			countSet++;
	}

	if (countSet == k)
		return 1;
	else return 0;
}
void solve(int i, int sum, int size, int kcount)
{
	if (i == size)
	{
		int checkValue = update(size);
		if (checkValue == 1 && sum == n)
			subsetCount++;
		return;
	}

	binary[i] = 0;
	solve(i + 1, sum, size, kcount);

	binary[i] = 1;

	if (sum + subset[i] <= n && kcount <=k)
	{
		solve(i + 1, sum + subset[i], size, kcount+1);
	}

}
void read()
{
	int i = 0;
	while (primes[i] <= n)
	{
		subset[i] = primes[i];
		i++;
	}
	solve(0, 0, i,0);
}



void print()
{

}

void getPrime()
{
	int m = 2;
	//cout << 1 << ": "<< 2 << endl;
	primes[0] = 2;
	for (int i = 3; i <= 1121; i++)
	{
		int flag = 1;
		for (int j = 2; j <= i / 2; j++)
		{
			if (i%j == 0)
				flag = 0;
		}

		if (flag == 1)
		{
			//cout << m << ": " << i << endl;
			primes[m - 1] = i;
			m++;
		}
			
		
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	

	while (cin >> n >> k)
	{
		subsetCount = 0;
		if (n != 0 || k != 0)
		{
			//getPrime();
			read();
			cout << subsetCount << endl;
		}
		else break;

	}
	return 0;
}
