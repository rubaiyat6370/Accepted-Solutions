#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1001
int A[MAX];
int B[MAX];
int N;
int isFound=0;
int index;
int t=1;
int r;
int data[MAX];
void readCase(){
	int i;
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
}
void print(){
	int i;
	for(i=0;i<r;i++){
		printf("%d ",data[i]);
	}
	printf("\n");
}
void solveCase(int level, int  pos){
	if(level==r){
		print();
		return;
	}
	int i;
	for(i=pos;i<N;i++){
		data[level]=A[i];
		solveCase(level+1,i+1);
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&N,&r)==2){
		readCase();
		solveCase(0,0);
	}
}
