#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define NULLPTR NULL
using namespace std;

struct node{
	node *children[26];
    int numberOfChildren;
	bool isEndOfWord;
};

node *root;
int T;
int counter;

node * createNode(){
	node *newNode = (node*)malloc(sizeof(node));

	for (int i = 0; i < 26; i++){
		newNode->children[i] = NULLPTR;
	}
    newNode->numberOfChildren = 0;
	newNode->isEndOfWord = false;
	return newNode;
}

void insert(char * word){
	
	node *cur = root;
	int i = 0;
	while (word[i]){
		int pos = word[i] - 'a';
		if (cur->children[pos] == NULLPTR){
			cur->children[pos] = createNode();
           
		}
        cur->children[pos]->numberOfChildren++;
		cur = cur->children[pos];
		i++;
	}
	cur->isEndOfWord = true;
	
}

void findSuffix(node * cur){
	if (cur->isEndOfWord){
		counter++;
	}

	for (int i = 0; i < 26; i++){
		if (cur->children[i] != NULLPTR){
			findSuffix(cur->children[i]);
		}
	}
}

void search(char * word){
	node *cur = root;

	for (int i = 0; word[i]; i++){
		int pos = word[i] - 'a';
		if (cur->children[pos] != NULLPTR){
			cur = cur->children[pos];
		}
		else{
			return;
		}
	}
	if (cur != NULLPTR){
		counter  = cur->numberOfChildren;
	}

}

bool isEqual(char *query1, char *query2){
	for (int i = 0; query2[i]; i++){
		if (query1[i] != query2[i])
			return false;
	}
	return true;
}

int main(){
	root = createNode();

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> T;
	
	char query[10] = ""; 
	char input[26] = "";

	while (T--){
		cin >> query;
		counter = 0;
		if (isEqual(query,"add")){
			cin >> input;
			insert(input);
		}
		if (isEqual(query, "find")){
			cin >> input;
			search(input);
			cout << counter << endl;
		}

		
	}
	
	//char str[26] = "";
	//print(root, str, 0);
	return 0;
}
