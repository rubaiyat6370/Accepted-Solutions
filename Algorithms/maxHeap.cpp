#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int heap[1000];
int heapcount;

void initialize(){
	heapcount = 0;
	for (int i = 0; i < 1000; i++){
		heap[i] = -1;
	}
}

int getLeft(int i){
	return 2 * i + 1;
}

int getRight(int i){
	return 2 * i + 2;
}

void swapHeap(){
	int max = heap[0];
	int last = heap[heapcount - 1];
	heap[0] = last; 
}

void extraction() {
	swapHeap();
	heapcount--;
	int i = 0;
	while (i < heapcount) {
		int left = getLeft(i);
		int right = getRight(i);
		int des;
		if (left < heapcount && right >= heapcount){
			des = left;
		}
		else if (right < heapcount && left >= heapcount){
			des = right;
		}
		else if (right >= heapcount && left >= heapcount){
			break;
		}
		else {
			des = heap[left] > heap[right] ? left : right;
		}
		if (heap[des] > heap[i]){
			int l = heap[des];
			heap[des] = heap[i];
			heap[i] = l;
			i = des;
		}
		else {
			break;
		}
		
	}
}

void maxHeapify(int i){
	heapcount++;
	while (i!=0){
		int parent;
		if (i % 2 == 0){
			parent = (i / 2) - 1;
		}
		else {
			parent = i / 2;
		}
		if (parent < 0) return;
		if (heap[parent] < heap[i]){
			int temp = heap[parent];
			heap[parent] = heap[i];
			heap[i] = temp;
		}
		i = parent;
	}
}

void insertHeap(int x){
	heap[heapcount] = x;
	maxHeapify(heapcount);
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n = 0;
	heapcount = 0;
	initialize();
	cin >> n;
	for (int i = 0; i < n; i++){
		int c;
		cin >> c;
		insertHeap(c);
	}

	while (1){
		char y;
		cout << "Do you want to extract max?\nType y for YES and n for NO" << endl;
		cin >> y;
		if (y == 'y'){
			extraction();
			cout << heap[0] << endl;
		}
		else {
			break;
		}
	}
	return 0;
}

/**
10
3 10 11 5 8 12 4 45 1
**/
