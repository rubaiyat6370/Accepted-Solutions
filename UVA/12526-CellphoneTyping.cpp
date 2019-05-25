#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#define SIZE_M 27
#define NULLPTR NULL
using namespace std;

struct trieNode{
	trieNode *child[SIZE_M];
	int counter;
};

trieNode *root;
char list[1100010];
int length;

trieNode* createNode(){
	trieNode *node = (trieNode*)malloc(sizeof(trieNode));

	for (int i = 0; i < SIZE_M; i++){
		node->child[i] = NULLPTR;
	}

	node->counter = 0;
	return node;
}

void insert(char *str){
	trieNode *cur = root;

	for (int i = 0; str[i]; i++){
		int pos = str[i] - 'a';
		list[length++] = str[i];
		if (cur->child[pos] == NULLPTR) {
			cur->child[pos] = createNode();
		}
		cur = cur->child[pos];
		cur->counter++;
	}
	list[length++] = '.';
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
	float total;
	while (cin >> T){
		root = createNode();
		total = 0;
		length = 0;
		for (int k = 0; k < T; k++){
			char str[82];
			cin >> str;
			insert(str);
		}
		list[length++] = '\0';

		char str[82];
		int j = 0;
		for (int i = 0; list[i]; i++){
			if (list[i] != '.'){
				str[j++] = list[i];
			}
			if (list[i] == '.'){
				str[j] = '\0';
				total = total + search(str);
				j = 0;
				char str[82];
			}
		}
		float avg = (total / T);
		
		printf("%.2f\n", avg);
	}
	return 0;
}
