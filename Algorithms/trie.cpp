#define _CRT_SECURE_NO_WARNINGS

#include <iostream>                                              
 
using namespace std;

struct node {                                     
	int cnt;
	int nxt[30];
	node()
	{
		cnt = 0;
		for (int i = 0; i <= 29; i++)
			nxt[i] = -1;
	}
} tree[100005];

string ss[100005];
int n, index;

void insert(string s)
{
	int nw = 0;
	for (int i = 0; i<s.size(); i++)
	{
		int id = s[i] - '0';
		if (tree[nw].nxt[id] == -1)
		{
			tree[nw].nxt[id] = ++index;
		}
		nw = tree[nw].nxt[id];
		tree[nw].cnt++;
	}
	return;
}

int chk(string s)
{
	int nw = 0;
	for (int i = 0; i<s.size(); i++)
	{
		nw = tree[nw].nxt[s[i] - '0'];
		if (i == s.size() - 1 && tree[nw].cnt>1)
			return 1;
	}
	return 0;
}

