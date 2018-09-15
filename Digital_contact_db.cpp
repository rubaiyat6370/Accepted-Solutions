#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define NULLPTR NULL

using namespace std;

struct contact{
	contact *child[27];
	int isRealInput;
	int counter;
	int id;
};

static int id;
contact *root;

contact * createContact(){
	contact* newC = (contact*)malloc(sizeof(contact));

	for (int i = 0; i < 27; i++){
		newC->child[i] = NULLPTR;
	}
	newC->isRealInput = 0;
	newC->counter = 0;
	newC->id = 0;

	return newC;
}

void Add(char *name){
	contact * cur = root;

	for (int i = 0; name[i]; i++){
		int pos = name[i] - 'A';

		if (cur->child[pos] == NULLPTR){
			cur->child[pos] = createContact();
		}

		if (cur->child[pos]->id == id){
			cur = cur->child[pos];
		}
		else{
			cur = cur->child[pos];
			cur->counter++;
			cur->id = id;
		}
		
	}
	
}

void insertA(char *name){
	contact * cur = root;

	for (int i = 0; name[i]; i++){
		int pos = name[i] - 'A';

		if (cur->child[pos] == NULLPTR){
			cur->child[pos] = createContact();
		}
		cur = cur->child[pos];
	}
	cur->isRealInput++;
}

void Add(char *name, int name_length){
	id++;
	insertA(name);
	char *p;
	p = name;
	for (int i = 0; name[i]; i++){
		char strng[21];
		int j;
		for (j = 0; p[j]; j++){
			strng[j] = p[j];
		}
		strng[j] = '\0';
		Add(strng);
		p++;
	}

}

int Search(char *query_string, int query_string_length){
	contact *cur = root;

	for (int i = 0; query_string[i]; i++){
		int pos = query_string[i] - 'A';

		if (cur->child[pos] == NULLPTR){
			return 0;
		}
		cur = cur->child[pos];
	}
	return cur->counter;
}

bool isRealContact(char * name){
	contact *cur = root;

	for (int i = 0; name[i]; i++){
		int pos = name[i] - 'A';

		if (cur->child[pos] == NULLPTR){
			return 0;
		}
		cur = cur->child[pos];
	}
	if (cur->isRealInput > 0){ //should not reduce the number 
		cur->isRealInput--;
		return true;
	}
	return false;
}

void Delete(char *name){
	contact *cur = root;

	for (int i = 0; name[i]; i++){
		int pos = name[i] - 'A';

		if (cur->child[pos] == NULLPTR){
			return;
		}

		if (cur->child[pos]->id == id){
			cur = cur->child[pos];
		}
		else{
			cur = cur->child[pos];
			cur->counter--;
			cur->id = id;
		}
	}
	
}

void Delete(char *name, int name_length){

	if (isRealContact(name)){
		id++;
		char *p;
		p = name;
		for (int i = 0; name[i]; i++){
			char strng[21];
			int j;
			for (j = 0; p[j]; j++){
				strng[j] = p[j];
			}
			strng[j] = '\0';
			Delete(strng);
			p++;
		}
	}
}

void Init(){
	id = 0;
	root = createContact();
}




int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int case_count;
	scanf("%d", &case_count);
	int i = 0;
	while (case_count--)
	{

		Init();

		int query_count;
		scanf("%d", &query_count);

		while (query_count--)
		{

			int query_type;
			scanf("%d", &query_type);

			switch (query_type)
			{
			case 1:
			{
				char name[100];
				int name_length;
				scanf("%d %s", &name_length, &name);

				Add(name, name_length);
				break;
			}
			case 2:
			{
				char name[100];
				int name_length;
				scanf("%d %s", &name_length, &name);

				Delete(name, name_length);
				break;
			}
			case 3:
			{
				i++;
				char query_string[100];
				int query_string_length;
				scanf("%d %s", &query_string_length, &query_string);

				int answer = Search(query_string, query_string_length);

				printf("%d %d\n", i, answer);
				break;
			}
			}
		}
	}
	return 0;
}
