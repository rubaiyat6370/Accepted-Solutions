#include <malloc.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define NULLPTR NULL
#define LENGTH 801
#define WIDTH 201

struct box{
	int height;
	box *next;
};


struct  grid
{
	box* maxHeight;
	int totalHeight;
	box* boxList; //head
};

grid ware_house[LENGTH][WIDTH];

box *createNewBox(int data){
	box * nBox = (box*)malloc(sizeof(box));

	nBox->height = data;
	nBox->next = NULLPTR;

	return nBox;
}

grid* createGrid(){
	grid *ngrid = (grid*)malloc(sizeof(grid));
	ngrid->maxHeight = NULLPTR;
	ngrid->totalHeight = 0;
	ngrid->boxList = NULLPTR;

	return ngrid;
}

void freeList(box *b){
	box *cur = b;
	while (b != NULLPTR){
		b = b->next;
		free(cur);
		cur = b;
	}
}


//------------------------------ Mumu --------------------------------//

void myInit(int length, int width)
{
	for (int i = 1; i < length; i++){
		for (int j = 1; j < width; j++){

			freeList(ware_house[i][j].boxList);
			ware_house[i][j].boxList = NULLPTR;
			freeList(ware_house[i][j].maxHeight);
			ware_house[i][j].maxHeight = NULLPTR;
			ware_house[i][j].totalHeight = 0;
	
		}
	}
	return;
}

void myAdd(int x, int y, int h)
{
	if (ware_house[x][y].boxList == NULLPTR){
		ware_house[x][y].maxHeight = createNewBox(h);
		ware_house[x][y].totalHeight = h;
		ware_house[x][y].boxList = createNewBox(h);
	}
	else{
		if (ware_house[x][y].maxHeight->height <= h){
			box *mx = createNewBox(h);
			mx->next = ware_house[x][y].maxHeight;
			ware_house[x][y].maxHeight = mx;

		}
		ware_house[x][y].totalHeight = ware_house[x][y].totalHeight + h;
		box *cur = ware_house[x][y].boxList;
		box *nbox = createNewBox(h);
		nbox->next = ware_house[x][y].boxList;
		ware_house[x][y].boxList = nbox;
	}
	return;
}

void myRemove(int x, int y)
{

		if (ware_house[x][y].boxList!=NULLPTR){

			ware_house[x][y].totalHeight = ware_house[x][y].totalHeight - ware_house[x][y].boxList->height;
			box *temp;
			if (ware_house[x][y].maxHeight->height == ware_house[x][y].boxList->height){
				temp = ware_house[x][y].maxHeight;
				ware_house[x][y].maxHeight = ware_house[x][y].maxHeight->next;
				free(temp);
			}
			temp = ware_house[x][y].boxList;
			ware_house[x][y].boxList = ware_house[x][y].boxList->next;
			free(temp);
		}
		
	return;
}

int mySearch(int x, int y, int l, int w)
{
	int mx = 0;
	int lastX = x + l;
	int lastY = y + w;
	for (int i = x; i < lastX; i++){
		for (int j = y; j < lastY; j++){
			if (ware_house[i][j].maxHeight && ware_house[i][j].maxHeight->height > mx)
				mx = ware_house[i][j].maxHeight->height;
		}
	}
	return mx;
}

int mySum(int x, int y, int l, int w)
{
	int total = 0;
	int lastX = x + l;
	int lastY = y + w;
	for (int i = x; i < lastX; i++){
		for (int j = y; j < lastY; j++){
			total = total + ware_house[i][j].totalHeight;
		}
	}
	return total;
}

//------------------------------ Mumu --------------------------------//


struct inputParams
{
	int x, y, l, w, h, height, width;
};

//trie
int isTrieCreated;

struct tNode
{
	tNode* next[26];
	int isLeaf;
	int index;
};

tNode* root;

tNode* createNode()
{
	tNode* newNode = (tNode*)malloc(sizeof(tNode));
	newNode->isLeaf = 0;
	for (int i = 0; i < 26; i++)
	{
		newNode->next[i] = NULL;
	}
	newNode->index = 0;
	return newNode;
}

void insert(tNode* root, char *str, int leafIndex)
{
	tNode* cur = root;
	for (int i = 0; str[i]; i++)
	{
		int index = str[i] - 'a';
		if (cur->next[index] == NULL)
		{
			cur->next[index] = createNode();
		}
		cur = cur->next[index];
	}

	cur->isLeaf = 1;
	cur->index = leafIndex;
}

int search(tNode* root, char *str)
{
	tNode* cur = root;
	for (int i = 0; str[i]; i++)
	{
		int index;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			index = str[i] - 'a';
		}
		else
		{
			continue;
		}

		if (cur->next[index] == NULL)
		{
			return -1;
		}

		cur = cur->next[index];
	}

	if (cur != NULL && cur->isLeaf)
	{
		return cur->index;
	}
	return -1;
}
//trie

inputParams param;


void setValue(int index, int value)
{
	if (index == 1)
	{
		param.width = value;
	}
	else if (index == 2)
	{
		param.height = value;
	}
	else if (index == 3)
	{
		param.x = value;
	}
	else if (index == 4)
	{
		param.y = value;
	}
	else if (index == 5)
	{
		param.w = value;
	}
	else if (index == 6)
	{
		param.l = value;
	}
	else if (index == 7)
	{
		param.h = value;
	}
}

char key[1000];
char val[1000];

int getValue()
{
	int len = 0;
	for (; val[len]; len++);
	int multi = 1;

	int sum = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		sum += (val[i] - '0') * multi;
		multi *= 10;
	}
	return sum;
}


void init()
{
	if (!isTrieCreated)
	{
		isTrieCreated = 1;
		root = createNode();
		insert(root, "width", 1);
		insert(root, "length", 2);
		insert(root, "x", 3);
		insert(root, "y", 4);
		insert(root, "w", 5);
		insert(root, "l", 6);
		insert(root, "h", 7);
	}
}


void parseInput(char* arg)
{
	int keyIndex = 0;
	int valIndex = 0;
	int keyFound = 0;
	int valuFound = 1;


	for (int i = 0; arg[i]; i++)
	{
		if (arg[i] == ' ' || arg[i] == '{')
		{
			continue;
		}
		else if (arg[i] == ',' || arg[i] == '}')
		{
			val[valIndex] = '\0';

			valuFound = 1;
			keyFound = 0;
			valIndex = 0;
			keyIndex = 0;

			int index = search(root, key);
			if (index >= 1 && index <= 7)
			{
				setValue(index, getValue());
			}

		}
		else if (arg[i] == ':')
		{
			key[keyIndex] = '\0';
			keyIndex = 0;
			valIndex = 0;
			keyFound = 1;
			valuFound = 0;
		}
		else
		{
			if (keyFound)
			{
				val[valIndex++] = arg[i];
			}
			else
			{
				key[keyIndex++] = arg[i];
			}
		}
	}
}

void init(char* arg_obj){
	init();
	parseInput(arg_obj);
	myInit(param.height, param.width);
	return;
}

void add(char* arg_obj){
	parseInput(arg_obj);
	myAdd(param.x, param.y, param.h);
	return;
}

void remove(char* arg_obj){
	parseInput(arg_obj);
	myRemove(param.x, param.y);
	return;
}

int search_max(char* arg_obj){
	parseInput(arg_obj);
	return mySearch(param.x, param.y, param.l, param.w);
}

int calc_sum(char* arg_obj){
	parseInput(arg_obj);
	return mySum(param.x, param.y, param.l, param.w);
}
