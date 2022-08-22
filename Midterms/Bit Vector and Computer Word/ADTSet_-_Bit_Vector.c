#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef int SET[SIZE];

void initSET(SET A);
void insert(SET A, int n);
void deleteMem(SET A, int n);
void populateA(SET A);
void populateB(SET B);
void display(SET A);

//set operations
int isMember(SET A, int n);
SET* unionSet(SET A, SET B);
SET* intersection(SET A, SET B);
SET* difference(SET A, SET B);
int isSubset(SET A, SET B);

int main() {
	SET A,B;
	initSET(A);
	initSET(B);
	populateA(A);
	populateB(B);	
		
	display(A);
	display(B);

	printf("\n");	
	
	SET* U = unionSet(A,B);
	SET* I = intersection(A,B);
	SET* D = difference(A,B);
	
	display(*U);
	display(*I);
	display(*D);
	
	printf("\n");
	printf("%d ",isMember(A,9));  // 1
	printf("%d ",isSubset(A,B));  // 0
	deleteMem(A,9);
	printf("%d ",isMember(A,9));  // 0
	printf("%d ",isSubset(A,B));  // 1
	
	return 0;
}

void populateA(SET A){
	int num[] = {5, 7, 9}, x;
	for(x=0;x<3;x++){
		insert(A,num[x]);
	}
}

void populateB(SET B){
	int num[] = {3, 5, 7, 11, 13, 15}, x;
	for(x=0;x<6;x++){
		insert(B,num[x]);
	}
}


void initSET(SET A){
	int x;
	for(x=0;x<SIZE;x++){
		A[x] = 0;
	}
}

void insert(SET A, int n){
	if(n>=0 && n<SIZE)
	A[n] = 1;
}

void deleteMem(SET A, int n){
	if(n>=0 && n<SIZE)
	A[n] = 0;
}

void display(SET A){
	int x;
	for(x=0; x<SIZE; x++){
		if(A[x]==1)
		printf("%d ",x);
	}
	printf("\n");
}

int isMember(SET A, int n){
	return A[n];
}

SET* unionSet(SET A, SET B){
	int x;
	SET* C = (SET*)calloc(1,sizeof(SET));
	if(C != NULL){
		for(x=0; x<SIZE; x++){
			(*C)[x] = A[x] | B[x]; 
		}
	}
	return C;
}

SET* intersection(SET A, SET B){
	int x;
	SET* C = (SET*)calloc(1,sizeof(SET));
	if(C != NULL){
		for(x=0; x<SIZE; x++){
			(*C)[x] = A[x] & B[x]; 
		}
	}
	return C;
}

SET* difference(SET A, SET B){ //A – B
	int x;
	SET* C = (SET*)calloc(1,sizeof(SET));
	if(C != NULL){
		for(x=0; x<SIZE; x++){
			(*C)[x] = A[x] & ~B[x]; 
		}
	}
	return C;
}

int isSubset(SET A, SET B){ //A subset of B
	int x;
	for(x=0; x<SIZE && (A[x] & ~B[x]) == 0; x++){}
	return (x==SIZE) ? 1 : 0;
}


