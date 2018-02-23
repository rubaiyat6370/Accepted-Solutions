#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector <int> climbingLeaderboard(vector <int> scores, vector <int> alice) {
	vector<int> ranks;
	long long s = scores.size();
	for (long long i = 0;i <alice.size();i++) {
		if ((alice[i] < scores[scores.size() - 1])) {
			ranks.push_back(scores.size() + 1);
		}
		else if (alice[i] >= scores[0]) {
			ranks.push_back(1);
		}
		else {
			for (long long j = s - 1;j >= 0;j--) {

				if (alice[i] >= scores[j] && alice[i]<scores[j - 1]) {
					ranks.push_back(j + 1);
					s = j + 1;
					break;
				}
			}
		}
	}
	return ranks;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> scores;
	int high = 0;
	int i = 0;
	cin >> high;
	scores.push_back(high);
	for (int scores_i = 1; scores_i < n; scores_i++) {
		cin >> high;
		if (scores[i] > high)
		{
			scores.push_back(high);
			i++;
		}

	}
	int m;
	cin >> m;
	vector<int> alice(m);
	for (int alice_i = 0; alice_i < m; alice_i++) {
		cin >> alice[alice_i];
	}
	vector <int> result = climbingLeaderboard(scores, alice);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << (i != result.size() - 1 ? "\n" : "");
	}
	cout << endl;


	return 0;
}
