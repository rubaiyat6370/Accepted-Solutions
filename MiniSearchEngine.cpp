#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define NULLPTR NULL
#define SIZE_DOC 1000000+5
#define SIZE_N 128

using namespace std;


struct index{
	int data;
	index *next;
};

struct id{
	int data;
	index * head;
	id *next;
};

struct word{
	word *child[SIZE_N];
	id *head;
	bool isEnd;
};

word *root;
int ids[SIZE_DOC];

index * createIndex(int data){
	index *idx = (index*)malloc(sizeof(index));
	
	idx->data = data;
	idx->next = NULLPTR;
	return idx;
	
}

id * createId(int data){
	id* ID = (id*)malloc(sizeof(id));
	ID->data = data;
	ID->next = NULLPTR;
	ID->head = NULLPTR;

	return ID;

}

word * createWord(){
	word *nWord = (word*)malloc(sizeof(word));

	for (int i = 0; i < SIZE_N; i++){
		nWord->child[i] = NULLPTR;
	}

	nWord->isEnd = false;
	nWord->head = NULLPTR;

	return nWord;
}

void insertIndex(id* ID, int idx){
	
	index *nIdx = createIndex(idx);

	if (ID->head == NULLPTR){
		ID->head = nIdx;
	}
	else{
		index *curIdx = ID->head;
		while (curIdx != NULLPTR && curIdx->next != NULLPTR){
			curIdx = curIdx->next;
		}
		curIdx->next = nIdx;
	}
}

void insertDocId(word* curWord, int ID, int idx){
	
	
	id* nID = createId(ID);

	if (curWord->head == NULLPTR){
		curWord->head = nID;
		insertIndex(curWord->head, idx);
	}
	else{
		id* curID = curWord->head;
		while (curID != NULLPTR && curID->next != NULLPTR){
			if (curID->data == ID){
				insertIndex(curID, idx);
				return;
			}
			curID = curID->next;
		}

		if (curID->data == ID){
			insertIndex(curID, idx);
			return;
		}

		curID->next = nID;
		insertIndex(curID->next, idx);
	}

	ids[ID] = 1;
}

void insertNewWord(int ID, char *str, int idx){
	word *nWord = root;

	for (int i = 0; str[i]; i++){
		int pos = (int) str[i];

		if (nWord->child[pos] == NULLPTR){
			nWord->child[pos] = createWord();
		}
		nWord = nWord->child[pos];
	}
	nWord->isEnd = true;
	insertDocId(nWord, ID, idx);
}

void deleteWord(int ID){
	ids[ID] = 0;
}


word *returnFoundWord(char *str){
	word *cur = root;

	for (int i = 0; str[i]; i++){
		int pos = (int)str[i];

		if (cur->child[pos] == NULLPTR){
			return NULLPTR;
		}
		cur = cur->child[pos];
	}

	return cur;
}

void searchAndPrintID(char *str){
	
	word *cur = returnFoundWord(str);
	if (cur == NULLPTR){
		cout << "-1" << endl;
		return;
	}

	if (cur->isEnd){
		id *curID = cur->head;
		
		bool flag = 1;
		
		while (curID != NULLPTR){

			if (ids[curID->data] == 1){
				while (flag)
				{
					cout << "DocID: ";
					flag = 0;
				}
				cout << curID->data << " ";
			}
			curID = curID->next;
		}
		if (flag)
		{
			cout << "-1" << endl;
			return;
		}
		cout << endl;
	}
}

void searchAndPrintIDAndIndex(char *str){
	word *cur = returnFoundWord(str);
	if (cur == NULLPTR){
		cout << "-1" << endl;
		return;
	}
	if (cur->isEnd){
		id *curID = cur->head;
		bool isfound = 0;

		while (curID != NULLPTR){
			
			if (ids[curID->data] == 1){
				cout << "DocID: ";
				isfound = 1;
		
				cout << curID->data << " ";

				index *curIdx = curID->head;
				cout << "Index: ";

				while (curIdx != NULLPTR){
					cout << curIdx->data << " ";
					curIdx = curIdx->next;
					
				}
				
				cout << endl;
			}
			curID = curID->next;
		}

		if (!isfound)
		{
			cout << "-1" << endl;
			return;
		}
	}
}

void init(){
	for (int i = 0; i < SIZE_DOC; i++){
		ids[i] = 0;
	}
	root = createWord();
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;
	init(); 
	while (T--){
		int type;
		int ID;
		char str[22];
		int idx;

		//initialize the data structure for further test cases

		cin >> type;

		if (type == 1){
			//search and print id
			cin >> str;
			searchAndPrintID(str);
		}
		if (type == 2){
			//search and print id nd index
			cin >> str;
			searchAndPrintIDAndIndex(str);
		}
		if (type == 3){
			//delete
			cin >> ID;
			deleteWord(ID);
		}
		if (type == 4){
			//insert
			cin >> ID;
			cin >> idx;

			for (int i = 0; i < idx; i++){
				cin >> str;
				insertNewWord(ID, str, i);
			}
		}
	}
	return 0;
}
