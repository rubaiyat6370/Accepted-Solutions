#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#define NULLPTR NULL

using namespace std;

int mx;

struct node{
	node *child[2];
	int childCounter;
	int pos;
};

node *root;

node* createNode(){
	node *data = (node*)malloc(sizeof(node));

	for (int i = 0; i < 2; i++){
		data->child[i] = NULLPTR;
	}
	data->childCounter = 0;
	data->pos = 0;

	return data;
}

void insertNode(char *str){
	node *cur = root;

	for (int i = 0; str[i]; i++){
		int pos = str[i] - '0';
		if (cur->child[pos] == NULLPTR){
			cur->child[pos] = createNode();
		}
		cur->child[pos]->childCounter++;
		if (cur->child[pos]->pos == 0){
			cur->child[pos]->pos = cur->pos + 1;
		}
		int longest = cur->child[pos]->pos * cur->child[pos]->childCounter;
		if (longest > mx)
			mx = longest;
		cur = cur->child[pos];
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	char str[201];

	while (T--){
		int n;
		cin >> n;
		root = createNode();
		mx = -1;
		char c ;
		getchar();
		while (n--){
			int i = 0;
			while (scanf("%c",&c) && c != '\n'){
				str[i++] = c;
			}
			str[i] = '\0';
			insertNode(str);
		}
		cout << mx << endl;
	}
	return 0;
}
