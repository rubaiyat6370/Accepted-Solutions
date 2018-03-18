#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>

struct word {
	char name[257];
};

using namespace std;
int wordNo, ruleNo, index;
word words[101];
char rule[257];
char output[257];

void initialize()
{
	
	for (int i = 0;i < 101;i++)
	{
		for (int j = 0;j < 257;j++) {
			words[i].name[j] = ' ';
		}
	}
	for (int i = 0;i < 257;i++)
	{
		rule[i] = ' ';
		output[i] = ' ';
	}
}

void print() {
	for (int i = 0;output[i];i++) {
		if (output[i] == '#')
			printf("%s", words[index].name);
		else {
			cout << output[i];
		}
	}
	cout << endl;
}
void solve(int i) {
	if (!rule[i]) {
		output[i] = rule[i];
		print();
		return;
	}
	else if(rule[i] == '#') {
		output[i] = rule[i];
		solve(i + 1);
	}
	else {
		for (int j = 0;j < 10;j++) {
			output[i] = j + '0';
			solve(i + 1);
		}
	}
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	while (cin >> wordNo) {
		for (int i = 0;i < wordNo;i++) {
			scanf("%s", words[i].name);
		}

		cin >> ruleNo;

		for (int i = 0;i < ruleNo;i++) {
			scanf("%s", &rule);
			cout << "--" << endl;
			for (index = 0;index < wordNo;index++) {
				solve(0);
				//cout << endl;
			}
		}
	}
	return 0;
}
/*
input:
2
root
2super
1
#0
1
admin
1
#0#

output:
--
root0
root1
root2
root3
root4
root5
root6
root7
root8
root9
2super0
2super1
2super2
2super3
2super4
2super5
2super6
2super7
2super8
2super9
--
admin0admin
admin1admin
admin2admin
admin3admin
admin4admin
admin5admin
admin6admin
admin7admin
admin8admin
admin9admin


*/