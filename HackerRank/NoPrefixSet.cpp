#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define NULLPTR NULL
using namespace std;

struct node{
	node *children[11];
	int numberOfChild;
	bool isEndOfWord;
};

node *root;
int T;
char output[61] = "";
bool isBadSet;

node * createNode(){
	node *newNode = (node*)malloc(sizeof(node));

	for (int i = 0; i < 11; i++){
		newNode->children[i] = NULLPTR;
	}
	newNode->numberOfChild = 0;
	newNode->isEndOfWord = false;
	return newNode;
}

bool isEqual(char *query1, char *query2){
	for (int i = 0; query2[i]; i++){
		if (query1[i] != query2[i])
			return false;
	}
	return true;
}

void insert(char word[]){
	
	node *cur = root;
	int i = 0;
	while (word[i]){
		int pos = word[i] - 'a';
		if (cur->children[pos] == NULLPTR){
			cur->children[pos] = createNode();
		}
		cur->children[pos]->numberOfChild++;
		if (cur->children[pos]->isEndOfWord && cur->children[pos]->numberOfChild >1 && isEqual(output,"")){
			int j;
			for (j = 0; word[j]; j++)
				output[j] = word[j];
			output[j] = '\0';
			isBadSet = true;
		}
		cur = cur->children[pos];
		i++;
	}
	cur->isEndOfWord = true;
	if (cur->isEndOfWord && cur->numberOfChild >1 && isEqual(output, "")){
		int j;
		for (j = 0; word[j]; j++)
			output[j] = word[j];
		output[j] = '\0';
		isBadSet = true;
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
	
	}

}



void print(node * cur, char str[], int level){
	if (cur->isEndOfWord){
		str[level] = '\0';
		cout << str << endl;
	}

	for (int i = 0; i < 26; i++){
		if (cur->children[i] != NULLPTR){
			str[level] = i + 'a';
			print(cur->children[i], str, level + 1);
		}
	}
}

int main(){
	root = createNode();

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> T;
	
	char query[61] = ""; 
	
	isBadSet = false;
	while (T-- && !isBadSet){
		cin >> query;
		insert(query);
	}
	
	if (!isBadSet){
		cout << "GOOD SET" << endl;
	}
	else{
		cout << "BAD SET" << endl;
		cout << output << endl;
	}
	
	return 0;
}
