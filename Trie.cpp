#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#define SIZE_M 27
#define NULLPTR NULL
using namespace std;

struct trieNode{
	trieNode *child[SIZE_M];
	int counter;
	bool isLast;
};

trieNode *root;

trieNode* createNode(){
	trieNode *node = (trieNode*)malloc(sizeof(trieNode));

	for (int i = 0; i < SIZE_M; i++){
		node->child[i] = NULLPTR;
	}

	node->counter = 0;
	node->isLast = false;
	return node;
}

void insert(char *str){
	trieNode *cur = root;

	for (int i = 0; str[i]; i++){
		int pos = str[i] - 'a';
		if (cur->child[pos] == NULLPTR) {
			cur->child[pos] = createNode();
		}
		cur = cur->child[pos];
		cur->counter++;
	}
	cur->isLast = true;
}

void recursivePrint(char str[81], trieNode *head, int x){
	trieNode* cur = head;
	for (int i = 0; i < 27; i++){
		if (cur->child[i] != NULLPTR){
			str[x] = i + 'a';

			if (cur->child[i]->isLast){
				str[x + 1] = '\0';
				cout << str << endl;
			}

			recursivePrint(str, cur->child[i], x + 1);
		}
	}
}

int search(char *str){
	trieNode *cur = root;
	int stroke = 1;
	int max = -1;
	for (int i = 0; str[i]; i++){
		int pos = str[i] - 'a';
		if (max == -1) {
			max = cur->child[pos]->counter;
		}
		else{
			if (cur->child[pos]->counter < max){
				stroke++;
				max = cur->child[pos]->counter;
			}
		}
		cur = cur->child[pos];
	}
	return stroke;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;

	while (cin >> T){
		root = createNode();
		char str[81];
		for (int k = 0; k < T; k++){
			char str[82];
			cin >> str;
			insert(str);
		}
		recursivePrint(str, root, 0);
	}
	return 0;
}


//* Sample Input *//
4
hello
hell
heaven
goodbye
3
hi
he
h
7
structure
structures
ride
riders
stress
solstice
ridiculous

/** Sample output **/
goodbye
heaven
hell
hello
h
he
hi
ride
riders
ridiculous
solstice
stress
structure
structures
